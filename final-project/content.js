function checkAltAttributes() {
    let imagesWithoutAlt = [];
    document.querySelectorAll('img').forEach(img => {
        if (!img.hasAttribute('alt') || img.getAttribute('alt').trim() === '') {
            imagesWithoutAlt.push(img);
        }
    });
    return imagesWithoutAlt;
}

function checkContrast() {
    let lowContrastElements = [];

    const getContrastRatio = (lumA, lumB) => {
        var ratio,
            lighter,
            darker;

        if (lumA >= lumB) {
            lighter = lumA;
            darker = lumB;
        } else {
            lighter = lumB;
            darker = lumA;
        }

        ratio = (lighter + 0.05) / (darker + 0.05);

        return ratio;
    }
    
    document.querySelectorAll('*').forEach(el => {
        let style = window.getComputedStyle(el);
        let bgColor = style.backgroundColor;
        let textColor = style.color;

        if (!bgColor || !textColor || bgColor === 'rgba(0, 0, 0, 0)' || bgColor === 'transparent') {
            return;
        }

        try {
            let contrastRatio = getContrastRatio(textColor, bgColor);

            let fontSize = parseFloat(style.fontSize);
            let isLargeText = fontSize >= 18 || (fontSize >= 14 && style.fontWeight >= 700);

            if ((isLargeText && contrastRatio < 3) || (!isLargeText && contrastRatio < 4.5)) {
                lowContrastElements.push(el);
            }
        } catch (error) {
            console.error('Error processing colors:', error);
        }
    });

    return lowContrastElements;
}


function runAccessibilityChecks() {
    let results = {
        altIssues: checkAltAttributes(),
        contrastIssues: checkContrast(),
    };
    return results;
}

function highlightIssues(issues) {
    issues.altIssues.forEach(img => {
        img.style.border = '2px solid red';
        img.title = 'Missing alt attribute';
    });

    issues.contrastIssues.forEach(el => {
        el.style.outline = '2px solid red';
        el.title = 'Low contrast text';
    });
}

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    if (message.action === 'runChecks') {
        let issues = runAccessibilityChecks();
        highlightIssues(issues);
        sendResponse({ issues });
    }
});

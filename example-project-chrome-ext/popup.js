document.getElementById('run-checks').addEventListener('click', () => {
    chrome.tabs.query({ active: true, currentWindow: true }, (tabs) => {
        chrome.tabs.sendMessage(tabs[0].id, { action: 'runChecks' }, (response) => {
            if(response && response.issues){
                displayResults(response.issues);
            }
        });
    });
});

function displayResults(issues) {
    let resultsDiv = document.getElementById('results');
    resultsDiv.innerHTML = '';

    if (issues.altIssues.length > 0) {
        let currentIndex = 0;
        resultsDiv.innerHTML += `<p><strong>Images missing alt attributes:</strong> ${issues.altIssues.length}</p>`;
    } else {
        resultsDiv.innerHTML += `<p>All images have alt attributes.</p>`;
    }

    if (issues.contrastIssues.length > 0) {
        resultsDiv.innerHTML += `<p><strong>Low contrast text elements:</strong> ${issues.contrastIssues.length}</p>`;
    } else {
        resultsDiv.innerHTML += `<p>No low contrast issues found.</p>`;
    }
}
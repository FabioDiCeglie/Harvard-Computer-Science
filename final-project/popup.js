document.getElementById('toggle-reading-mode').addEventListener('click', () => {
    chrome.tabs.query({active: true, currentWindow: true}, (tabs) => {
      chrome.scripting.executeScript({
        target: {tabId: tabs[0].id},
        files: ['content.js']
      });
    });
});

document.getElementById('toggle-dark-mode').addEventListener('click', () => {
    chrome.storage.local.set({ theme: 'dark-mode' }, () => {
        chrome.tabs.query({ active: true, currentWindow: true }, (tabs) => {
            chrome.scripting.executeScript({
                target: { tabId: tabs[0].id },
                files: ['theme.js']
            });
        });
    });
});

document.getElementById('toggle-light-mode').addEventListener('click', () => {
    chrome.storage.local.set({ theme: 'light-mode' }, () => {
        chrome.tabs.query({ active: true, currentWindow: true }, (tabs) => {
            chrome.scripting.executeScript({
                target: { tabId: tabs[0].id },
                files: ['theme.js']
            });
        });
    });
});
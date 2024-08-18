function applyTheme() {
    chrome.storage.local.get(['theme'], (result) => {
        if (result.theme) {
            document.body.classList.remove('dark-mode', 'light-mode');
            document.body.classList.add(result.theme);
        }
    });
}

applyTheme();
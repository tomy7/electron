const { app, BrowserWindow } = require('electron')
const path = require('path')

let mainWindow = null

// Quit when all windows are closed.
app.on('window-all-closed', () => {
  app.quit()
})

exports.load = (appUrl) => {
  app.on('ready', () => {
    const options = {
      width: 900,
      height: 600,
      autoHideMenuBar: true,
      backgroundColor: '#FFFFFF',
      webPreferences: {
        nodeIntegrationInWorker: true
      },
      useContentSize: true,
      show: false
    }
    if (process.platform === 'linux') {
      options.icon = path.join(__dirname, 'icon.png')
    }

    mainWindow = new BrowserWindow(options)

    mainWindow.on('ready-to-show', () => mainWindow.show())

    mainWindow.loadURL(appUrl)
    mainWindow.focus()
  })
}

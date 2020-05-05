require('dotenv').config()
const webpack = require('webpack')

module.exports = {
    configureWebpack: (config) => {
        return { plugins: [
            new webpack.EnvironmentPlugin({ ...process.env })
        ]}
    },
    title: 'Ero',
    description: 'Ero Language',
    theme: 'thindark',
    themeConfig: {
        nav: [
            { text: 'Proposal', link: '/proposal' },
            { text: 'Demo', link: '/demo' }
        ]
    },
    markdown: {
        lineNumbers: true
    }
}
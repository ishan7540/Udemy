const http = require('http')
const fs = require('fs')
const path = require('path')

const port = 3000

const server = http.createServer();

server.listen(3000, () => {
    console.log("listening to port: ", port);
})


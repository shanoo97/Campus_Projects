let path = require('path');
let express = require('express');
let app = express();
const dbRouter = require('./dbRouter.js')
let mainRouter = require("./mainRouter.js")
const session = require('express-session');

app.use(session({
    secret: 'StringToEncryptCookie',
    resave: true,
    saveUninitialized: true
  }));

app.use("/", mainRouter);
app.use("/database", dbRouter.dbRouter);

let port = process.env.PORT || 3000;
let server = app.listen(port);
console.log("Express server running on port", port);

module.exports = {app:app,
  server : server }
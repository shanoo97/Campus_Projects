const path = require('path')
const express = require('express')
const mainRouter = express.Router()
const bodyParser = require('body-parser')
mainRouter.use(bodyParser.json())
mainRouter.use(bodyParser.urlencoded({ extended: true }))

mainRouter.get('/', function (req, res) {
  res.sendFile(path.join(__dirname, 'index.html'))
})

mainRouter.get('/about', function (req, res) {
  res.sendFile(path.join(__dirname, 'about.html'))
})

mainRouter.get('/account', function (req, res) {
  if (req.session.loggedIn === true) {
    res.header('Cache-Control', 'no-cache, private, no-store, must-revalidate, max-stale=0, post-check=0, pre-check=0')
    res.sendFile(path.join(__dirname, 'account.html'))
  } else {
    res.redirect('/login') 
}
})


mainRouter.get('/login', function (req, res) {
  if(req.session.InvalidLogin===true){
    res.sendFile(path.join(__dirname, 'login.html'))
  } else if (req.session.loggedIn === true) {
    res.redirect('/account')
  } else { 
res.header('Cache-Control', 'no-cache, private, no-store, must-revalidate, max-stale=0, post-check=0, pre-check=0') 
    res.sendFile(path.join(__dirname, 'login.html')) 
}
})

mainRouter.get('/updatedetails', function (req, res) {
  if (req.session.loggedIn===true) {
    res.header('Cache-Control', 'no-cache, private, no-store, must-revalidate, max-stale=0, post-check=0, pre-check=0')
    res.sendFile(path.join(__dirname, 'updatedetails.html'))
  }
  else{
    res.redirect('/login')}

})

mainRouter.get('/signup', function (req, res) {
  if (req.session.loggedIn===true) {
    res.header('Cache-Control', 'no-cache, private, no-store, must-revalidate, max-stale=0, post-check=0, pre-check=0')
    res.redirect('/account')
  }
  else{
    res.sendFile(path.join(__dirname, 'signup.html'))
}
  
})

mainRouter.get('/expenses', function (req, res) {

  if (req.session.loggedIn===true) {
    res.header('Cache-Control', 'no-cache, private, no-store, must-revalidate, max-stale=0, post-check=0, pre-check=0')
    res.sendFile(path.join(__dirname, 'expenses.html'))
  }
  else{
    res.redirect('/login')
}

  
})

mainRouter.get('/houses', function (req, res) {

  if (req.session.loggedIn===true) {
    res.header('Cache-Control', 'no-cache, private, no-store, must-revalidate, max-stale=0, post-check=0, pre-check=0')
    res.sendFile(path.join(__dirname, 'houses.html'))
  }
  else{
    res.redirect('/login')
}
})

mainRouter.get('/settledebt', function (req, res) {

  if (req.session.loggedIn===true) {
    res.header('Cache-Control', 'no-cache, private, no-store, must-revalidate, max-stale=0, post-check=0, pre-check=0')
    res.sendFile(path.join(__dirname, 'settledebt.html'))
  }
  else{
    res.redirect('/login')
}

  
})

mainRouter.use('/public', express.static('public'))

module.exports = mainRouter

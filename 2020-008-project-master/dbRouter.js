const mssql = require('mssql')
const path = require('path')
const express = require('express')
const dbRouter = express.Router()
const bodyParser = require('body-parser')
const session = require('express-session')
const md5 = require('md5')
fs = require('fs')
dbRouter.use(bodyParser.json())
dbRouter.use(bodyParser.urlencoded({ extended: true }))

// Make sure this is private to this module
const config = {
  server: 'eieserver.database.windows.net',
  database: 'db',
  // Put login details in env. variables for security
  user: 'salim',
  password: 'Lab@2020',
  port: 1433,
  // Required for Azure
  options: {
    encrypt: true,
    enableArithAbort: true
  },
  pool: {
    max: 10,
    min: 0,
    idleTimeoutMillis: 30000
  }
}
// Get a mssql connection instance
let isConnected = true
let connectionError = null
const pools = new mssql.ConnectionPool(config)
  .connect()
  .then(pool => {
    console.log('Connected to DB')
    return pool
  })
  .catch(err => {
    // Handle errors
    isConnected = false
    connectionError = err
    console.log(err)
  })



dbRouter.get('/', function (req, res) {
  // Make a query to the database
  pools
    // Run query
    .then((pool) => {
      return pool.request()
        // This is only a test query, change it to whatever you need
        .query('SELECT 1')
    })
    // Send back the result
    .then(result => {
      res.redirect('/')
      console.log(result)
    })
    // If there's an error, return that with some description
    .catch(err => {
      res.send({
        Error: err
      })
      console.log(err)
    })
})

dbRouter.post('/add', function (req, res) {
  pools
    // Run query
    .then((pool) => {
      return pool.request()
        // This is only a test query, change it to whatever you need
        .query(`INSERT INTO ClientInfo (first_name, last_name, email, username, password)\
            VALUES ('${req.body.name}', '${req.body.surname}', '${req.body.email}', '${req.body.username}', '${md5(req.body.password)}')`)
    })
    // Send back the result
    .then(result => {
      res.redirect('/login')
    })
    // If there's an error, return that with some description
    .catch(err => {
      res.redirect("/signup")
    })
})

dbRouter.post('/auth', function (req, res) {
  mean=0
  totalAmount=0
  amountbyCurrentID.splice(0,amountbyCurrentID.length)
  finalAmountYouAreOwed.splice(0,finalAmountYouAreOwed.length)
  finalAmountsOwed.splice(0,finalAmountsOwed.length)
  storeExpensesAfterAlgorithm.splice(0,storeExpensesAfterAlgorithm.length)
  storeDebtorsAfterAlgorithm.splice(0,storeDebtorsAfterAlgorithm.length)
  paidfrom.splice(0,paidfrom.length)
  paidtoar.splice(0,paidtoar.length)
  pools
    // Run query
    .then((pool) => {
      return pool.request()
        // This is only a test query, change it to whatever you need
        .query(`SELECT * FROM ClientInfo WHERE username='${req.body.userName_}' \
        AND password='${md5(req.body.psw)}'`)
    })
    // Send back the result
    .then(result => {
      if (result.recordset.length === 1) {
        req.session.clientid = result.recordset[0].id
        req.session.username = req.body.userName_
        req.session.password = req.body.psw
        req.session.email = result.recordset[0].email
        req.session.firstName = result.recordset[0].first_name
        req.session.lastName = result.recordset[0].last_name
        req.session.house = result.recordset[0].house
        req.session.loggedIn = true
        req.session.InvalidLogin = false

        pools
          // Run query
          .then((pool) => {
            return pool.request()

              .query(`SELECT * FROM ClientInfo WHERE house='${req.session.house}'`)
          })
          // Send back the result
          .then(result => {
            const members = []
            const memberID = []
            const memberUserName = []
            for (let i = 0; i < result.recordset.length; i++) {
              members.push(result.recordset[i].first_name)
              memberID.push(result.recordset[i].id)
              memberUserName.push(result.recordset[i].username)
            }
            req.session.members = members
            req.session.memberID = memberID
            req.session.memberUserName = memberUserName
            res.redirect('/database/getAmounts')
          })
          // If there's an error, return that with some description
          .catch(err => {
            res.send({
              Error: err
            })
            console.log(err)
          })
      } else {
        req.session.InvalidLogin = true
        res.redirect('/login')
      }
    })
    // If there's an error, return that with some description
    .catch(err => {
      res.send({
        Error: err
      })
      console.log(err)
    })
})


dbRouter.get('/newdata', function (req, res) {
  mean=0
  totalAmount=0
  iOweSomeone = false
  someoneOwesMe = false
  amountbyCurrentID.splice(0,amountbyCurrentID.length)
  finalAmountYouAreOwed.splice(0,finalAmountYouAreOwed.length)
  finalAmountsOwed.splice(0,finalAmountsOwed.length)
  storeExpensesAfterAlgorithm.splice(0,storeExpensesAfterAlgorithm.length)
  storeDebtorsAfterAlgorithm.splice(0,storeDebtorsAfterAlgorithm.length)
  paidfrom.splice(0,paidfrom.length)
  paidtoar.splice(0,paidtoar.length)
  console.log(req.session.username,req.session.password)
  pools
    // Run query
    .then((pool) => {
      return pool.request()
        // This is only a test query, change it to whatever you need
        .query(`SELECT * FROM ClientInfo WHERE username='${req.session.username}' \
        AND password='${md5(req.session.password)}'`)
    })
    // Send back the result
    .then(result => {
      console.log(result)
      if (result.recordset.length === 1) {
        
        req.session.clientid = result.recordset[0].id
        req.session.username = req.session.username
        req.session.password = req.session.password
        req.session.email = result.recordset[0].email
        req.session.firstName = result.recordset[0].first_name
        req.session.lastName = result.recordset[0].last_name
        req.session.house = result.recordset[0].house
        req.session.loggedIn = true
        req.session.InvalidLogin = false

        pools
          // Run query
          .then((pool) => {
            return pool.request()

              .query(`SELECT * FROM ClientInfo WHERE house='${req.session.house}'`)
          })
          // Send back the result
          .then(result => {
            const members = []
            const memberID = []
            const memberUserName = []
            for (let i = 0; i < result.recordset.length; i++) {
              members.push(result.recordset[i].first_name)
              memberID.push(result.recordset[i].id)
              memberUserName.push(result.recordset[i].username)
            }
            req.session.members = members
            req.session.memberID = memberID
            req.session.memberUserName = memberUserName
            res.redirect('/database/getAmounts')
          })
          // If there's an error, return that with some description
          .catch(err => {
            res.send({
              Error: err
            })
            console.log(err)
          })

      } else {
        req.session.InvalidLogin = true
        res.redirect('/login')
      }

    })
    // If there's an error, return that with some description
    .catch(err => {
      res.send({
        Error: err
      })
      console.log(err)
    })
})

dbRouter.post('/addHouse', function (req, res) {
  pools

    .then((pool) => {
      return pool.request()

        .query(`UPDATE ClientInfo \
            SET house = '${req.body.houseName}'\
            WHERE id = '${req.session.clientid}'\
            INSERT INTO HouseTable (houseName, password) \
            VALUES ('${req.body.houseName}', '${req.body.housepassword}')`)
      //     WHERE id = '${req.session.id}'`)
    })

    .then(result => {
      
      res.redirect('/database/newdata')

    })

    .catch(err => {
      res.redirect('/account')
    })
})

dbRouter.post('/joinHouse', function (req, res) {
  // Make a query to the database
  pools
    // Run query
    .then((pool) => {
      return pool.request()

        .query(`SELECT * FROM HouseTable WHERE houseName='${req.body.jhouseName}' \
        AND password='${req.body.jhousepassword}'\
        UPDATE ClientInfo \
        SET house = '${req.body.jhouseName}'\
        WHERE id = '${req.session.clientid}'`)
    })
    // Send back the result
    .then(result => {
      if (result.recordset.length === 1) { 
        
        res.redirect('/database/newdata') } 
        else { 
          res.redirect('/account') }
    })
    // If there's an error, return that with some description
    .catch(err => {
      res.send({
        Error: err
      })
      console.log(err)
    })
})


dbRouter.post('/leaveHouse', function (req, res) {
  pools
    // Run query
    .then((pool) => {
      return pool.request()

        .query(`UPDATE ClientInfo \
        SET house = null\
        WHERE id = ${req.session.clientid}`)
    })

    // Send back the result
    .then(result => {
      res.redirect('/database/newdata')
    })
    // If there's an error, return that with some description
    .catch(err => {
      res.send({
        Error: err
      })
      res.send('Invalid house')
      console.log(err)
    })
})

dbRouter.post('/changeDetails', function async (req, res) {
  if (req.body.name === '') {
    req.body.name = req.session.firstName
  }
  if (req.body.surname === '') {
    req.body.surname = req.session.lastName
  }
  if (req.body.username === '') {
    req.body.username = req.session.username
  }
  if (req.body.email === '') {
    req.body.email = req.session.email
  }
  if (req.body.password === '') {
    req.body.password = req.session.password
  }
   pools

    .then((pool) => {
      return pool.request()

        .query(`UPDATE ClientInfo \
            SET username = '${req.body.username}', first_name = '${req.body.name}', last_name = '${req.body.surname}', email = '${req.body.email}', password = '${md5(req.body.password)}'\
            WHERE id = '${req.session.clientid}'`)
    })

    .then(result => {
      req.session.username = req.body.username
      req.session.firstName = req.body.name
      req.session.lastName = req.body.surname
      req.session.password = req.body.password
      req.session.email = req.body.email
      res.redirect('/database/newdata')
    })

    .catch(err => {
      res.redirect('/updatedetails')
    })
})

dbRouter.get('/list', function (req, res) {
  res.json([req.session.clientid, req.session.username, req.session.email, req.session.password, req.session.firstName, req.session.lastName, req.session.loggedIn, req.session.house, req.session.data,
    req.session.paidtoar, req.session.paidfrom, req.session.peopleowingme, req.session.peopleIOwe])
})

dbRouter.post('/add-expense', function (req, res) {
  let exp_id = 0
  const d = new Date()
  pools
  // Run query

    .then((pool) => {
      return pool.request()
        .query(`INSERT INTO transactions (amount,description,addedby,date_added,house)\
              OUTPUT Inserted.id \
            VALUES (${req.body.amount}, '${req.body.items}', '${req.session.username}','${d}','${req.session.house}')`)
    })

    .then(result => {
      exp_id = result.recordset[0].id
      console.log(exp_id)
      res.redirect('/database/newdata')

    })
    // If there's an error, return that with some description
    .catch(err => {
      res.send({
        Error: err
      })
      console.log(err)
    })
})

dbRouter.post('/add-settlement', function (req, res) {
  let set_id = 0
  const d = new Date()
  pools
  // Run query

    .then((pool) => {
      return pool.request()
        .query(`INSERT INTO SettlementTable (amount, description, paidBy, paidTo, date, house,Payment_type)\
              OUTPUT Inserted.id \
            VALUES (-${req.body.amount}, '${req.body.items}', '${req.session.username}',  '${req.body.paidto}','${d}','${req.session.house}','${req.body.type}')`)
    })

    .then(result => {
      set_id = result.recordset[0].id
      res.redirect('/database/newdata')

    })
    // If there's an error, return that with some description
    .catch(err => {
      res.send({
        Error: err
      })
      console.log(err)
    })
})

dbRouter.get('/list1', function (req, res) {
  res.json([req.session.memberUserName, req.session.memberID, req.session.username])
})
dbRouter.get('/login-error', function (req, res) {
  res.json([req.session.InvalidLogin])
})
dbRouter.post('/logout', function (req, res) {
  mean=0
  totalAmount=0
  amountbyCurrentID.splice(0,amountbyCurrentID.length)
  finalAmountYouAreOwed.splice(0,finalAmountYouAreOwed.length)
  finalAmountsOwed.splice(0,finalAmountsOwed.length)
  storeExpensesAfterAlgorithm.splice(0,storeExpensesAfterAlgorithm.length)
  storeDebtorsAfterAlgorithm.splice(0,storeDebtorsAfterAlgorithm.length)
  paidfrom.splice(0,paidfrom.length)
  paidtoar.splice(0,paidtoar.length)
  req.session.destroy()
  res.redirect('/')
})
// --------------------------------------------------------------------------------------------------------

let amountbyCurrentID = []
let totalAmount = 0

dbRouter.get('/getAmounts', async function (req, res) {
  for (let i = 0; i < req.session.memberUserName.length; i++) {
    await pools
    // Run query

      .then((pool) => {
        return pool.request()

          .query(`SELECT * FROM transactions WHERE addedby='${req.session.memberUserName[i]}'\
                AND house = '${req.session.house}'`)
      })
      // Send back the result
      .then(result => {
        let eachMemberstotal = 0
        for (let i = 0; i < result.recordset.length; i++) {
          eachMemberstotal = eachMemberstotal + result.recordset[i].amount
          totalAmount = totalAmount + result.recordset[i].amount
        }
        amountbyCurrentID.push([req.session.memberUserName[i], eachMemberstotal])

        console.log('Balance of each house members expenses: ')
        console.log(amountbyCurrentID)
      })

      .catch(err => {
        res.send({
          Error: err
        })
        console.log(err)
      })
  }
  req.session.data = amountbyCurrentID
  res.redirect('/database/getSettlements')
})

let finalAmountsOwed = []
let mean = 0
dbRouter.get('/getMean', function (req, res) {
  pools
  // Run query

    .then((pool) => {
      return pool.request()

        .query('SELECT 1')
    })
    // Send back the result
    .then(result => {
      if (req.session.house !== null){
      req.session.amountbyCurrentID = amountbyCurrentID

      mean = (totalAmount / req.session.members.length).toFixed(2)
      for (let i = 0; i < req.session.memberUserName.length; i++) {
        let owedForThisUser = 0
        owedForThisUser = mean - req.session.amountbyCurrentID[i][1]
        finalAmountsOwed.push([req.session.memberUserName[i], -owedForThisUser.toFixed(2)])
      }
      console.log('Amounts owed by each member: ')
      console.log(finalAmountsOwed)

      minCashFlowRec(finalAmountsOwed, req.session.username)
      const peopleowingme = calcOwing(storeDebtorsAfterAlgorithm, paidfrom)
      const peopleIOwe = calcOwing(storeExpensesAfterAlgorithm, paidtoar)
      if (iOweSomeone === true) {
        req.session.peopleowingme = peopleowingme
        req.session.peopleIOwe = 0
        iOweSomeone = false
      } else if (someoneOwesMe === true) {
        req.session.peopleowingme = 0
        req.session.peopleIOwe = peopleIOwe
        someoneOwesMe = false
      }

      console.log(req.session.peopleowingme)
      console.log(req.session.peopleIOwe)
      res.redirect('/account')
    }
    else{
      peopleowingme=0
      res.redirect('/account')
    }
    })

    .catch(err => {
      res.send({
        Error: err
      })
      console.log(err)
    })
})

function getMin (arr) {
  let minInd = 0
  for (let i = 1; i < amountbyCurrentID.length; i++) {
    if (arr[i][1] < arr[minInd][1]) {
      minInd = i
    }
  }
  return minInd
}

function getMax (arr) {
  let maxInd = 0
  for (let i = 1; i < amountbyCurrentID.length; i++) {
    if (arr[i][1] > arr[maxInd][1]) {
      maxInd = i
    }
  }
  return maxInd
}

function minOf2 (x, y) {
  if (x < y) {
    return x
  } else {
    return y
  }
}

let storeExpensesAfterAlgorithm = []
let storeDebtorsAfterAlgorithm = []
let someoneOwesMe = false
let iOweSomeone = false

function minCashFlowRec(arr, req) {
  const mxCredit = getMax(arr)
  const mxDebit = getMin(arr)

  if (Math.round(arr[mxCredit][1]) === 0 && Math.round(arr[mxDebit][1]) === 0) {
    return
  }

  const min = minOf2(-arr[mxDebit][1], arr[mxCredit][1])
  arr[mxCredit][1] -= min
  arr[mxDebit][1] += min

  console.log(`${arr[mxDebit][0]} pays ${min.toFixed(2)} to ${arr[mxCredit][0]}`)

  if (arr[mxDebit][0] === req) {
    storeExpensesAfterAlgorithm.push([arr[mxCredit][0], min.toFixed(2)])
    console.log('This user to pay the following members: ')
    console.log(storeExpensesAfterAlgorithm)
    someoneOwesMe = true
  }
  if (arr[mxCredit][0] === req) {
    storeDebtorsAfterAlgorithm.push([arr[mxDebit][0], min.toFixed(2)])
    console.log('Users to pay this member: ')
    console.log(storeDebtorsAfterAlgorithm)
    iOweSomeone = true
  }

  minCashFlowRec(arr, req)
}

// ------------------------------------------------------------------------------------------------------------------
let paidtoar = []
dbRouter.get('/getSettlements', async function (req, res) {
  for (let i = 0; i < req.session.memberUserName.length; i++) {
    await pools
    // Run query

      .then((pool) => {
        return pool.request()
          .query(`SELECT distinct(paidTo) FROM SettlementTable WHERE paidBy='${req.session.username}'\
          AND house = '${req.session.house}'`)
      })
      // Send back the result
      .then(result => {
        pools
        // Run query

          .then((pool) => {
            return pool.request()
              .query(`SELECT * FROM SettlementTable WHERE paidBy='${req.session.username}' \
              AND paidTo='${req.session.memberUserName[i]}'`)
          })

          .then(result => {
            let totalamount = 0
            for (let j = 0; j < result.recordset.length; j++) {
              totalamount += result.recordset[j].amount
            }
            if (req.session.username !== req.session.memberUserName[i]) {
              paidtoar.push([req.session.memberUserName[i], totalamount])
              console.log(' The user settled with the following members: ')
              console.log(paidtoar)
            }
          })
          // If there's an error, return that with some description
          .catch(err => {
            res.send({
              Error: err
            })
            console.log(err)
          })
      })

      .catch(err => {
        res.send({
          Error: err
        })
        console.log(err)
      })
  }
  req.session.paidtoar = paidtoar
  res.redirect('/database/getSettlementsFromMembers')
})

let paidfrom = []
dbRouter.get('/getSettlementsFromMembers', async function (req, res) {
  for (let i = 0; i < req.session.memberUserName.length; i++) {
    await pools
    // Run query

      .then((pool) => {
        return pool.request()
          .query(`SELECT * FROM SettlementTable WHERE paidTo='${req.session.username}'\
          AND paidBy = '${req.session.memberUserName[i]}'\
          AND house = '${req.session.house}'`)
      })
      // Send back the result
      .then(result => {
        let totalamount = 0
        for (let j = 0; j < result.recordset.length; j++) {
          totalamount += result.recordset[j].amount
        }
        if (req.session.username !== req.session.memberUserName[i]) {
          paidfrom.push([req.session.memberUserName[i], totalamount])
          console.log('The following people have settled with this user: ')
          console.log(paidfrom)
        }
        //  calcOwing(storeDebtorsAfterAlgorithm, paidfrom)
      })

      .catch(err => {
        res.send({
          Error: err
        })
        console.log(err)
      })
  }
  req.session.paidfrom = paidfrom
  console.log('im here', paidfrom)
  res.redirect('/database/getMean')
})
//calcOwing(storeDebtorsAfterAlgorithm, paidfrom)
let finalAmountYouAreOwed = []

function calcOwing (arr1, arr2) {
  console.log('debtors', storeDebtorsAfterAlgorithm)
  console.log('people that made payments', paidfrom)
  for (let i = 0; i < arr1.length; i++) {
    let owed = 0
    for (let j = 0; j < arr2.length; j++) {
      if (arr1[i][0] === arr2[j][0]) {
        owed = parseFloat(arr1[i][1]) + arr2[j][1]
        finalAmountYouAreOwed.push([arr1[i][0], owed])
      }
    }
  }
  return finalAmountYouAreOwed
}

dbRouter.post('/log', function (req, res) {
  const data = []
  pools
    .then((pool) => {
      return pool.request()

        .query(`SELECT * FROM transactions WHERE house='${req.session.house}'`)
    })
    .then(result => {
      data.push(result.recordset)
      pools
        .then((pool) => {
          return pool.request()

            .query(`SELECT * FROM SettlementTable WHERE house='${req.session.house}'`)
        })
        .then(result => {
          data.push(result.recordset)



          let expenses = [['Expenses,\n\ndate added,amount,description,addedby']]
          fs.writeFileSync('text.csv', 'Expenses,\n\ndate added,amount,description,addedby\n')
          for (let i = 0; i < data[0].length; i++) {
            let temp = [data[0][i].date_added, data[0][i].amount, data[0][i].description, data[0][i].addedby]
            expenses.push(temp)
            fs.appendFileSync('text.csv', temp.toString() + '\n')
            temp = []
          }

          let settlements = ['date added,amount,description,paidby,paidto']
          fs.appendFileSync('text.csv', '\n\nSettlements\n\ndate added,amount,description,paidby,paidto\n')
          for (let i = 0; i < data[1].length; i++) {
            let temp = [data[1][i].date, data[1][i].amount * -1, data[1][i].description, data[1][i].paidBy, data[1][i].paidTo]
            settlements.push(temp)
            fs.appendFileSync('text.csv', temp.toString() + '\n')
            temp = []
          }


          res.download('text.csv')
          console.log(expenses)
          console.log(settlements)
        })
        .catch(err => {
          res.send({
            Error: err
          })
          console.log(err)
        })
    })
    .catch(err => {
      res.send({
        Error: err
      })
      console.log(err)
    })
})












module.exports = {
  dbRouter:dbRouter,
  pools: pools,
  calcOwing,
  minCashFlowRec,
  minOf2,
  getMax,
  getMin,
}


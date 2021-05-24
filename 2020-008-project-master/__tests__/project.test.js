
// /* eslint-env jest */

const app = require('../index')
const supertest = require('supertest')
const request=supertest(app.app)
const db = require("../dbRouter")
const session = require("express-session")
const dbRouter = require('../dbRouter')

afterAll(() => {      
  db.pools.then(pool=>(pool.close()))
  app.server.close()
})


describe("Connecting to different mainRouter pages", () => {

    test("Connecting to home page", async ()  => {
      jest.setTimeout(10000)
      const res= await request.get('/')
      expect(res.status).toEqual(200)
      
    });

    test("Connecting to login page", async ()  => {
      jest.setTimeout(30000)
      const res= await request.get('/login')
      expect(res.status).toEqual(200)
    });

    test("Connecting to about page", async ()  => {
      jest.setTimeout(30000)
      const res= await request.get('/about')
      expect(200).toEqual(200)
    });

    test("Connecting to signup page", async ()  => {
      jest.setTimeout(30000)
      const res= await request.get('/signup')
      expect(res.status).toEqual(200)
    });

    test("Connecting to houses page", async ()  => {
      jest.setTimeout(30000)
      const res= await request.get('/houses')
      expect(res.status).toEqual(302)
    });

    test("Connecting to houses page", async ()  => {
      jest.setTimeout(30000)
      const res= await request.get('/houses')
      expect(res.status).toEqual(302)
    });

    test("Connecting to update details page", async ()  => {
      jest.setTimeout(30000)
      const res= await request.get('/updatedetails')
      expect(res.status).toEqual(302)
    });

    test("Connecting to expenses page", async ()  => {
      jest.setTimeout(30000)
      const res= await request.get('/expenses')
      expect(res.status).toEqual(302)
    });

    test("Connecting to settledebt page", async ()  => {
      jest.setTimeout(30000)
      const res= await request.get('/settledebt')
      expect(res.status).toEqual(302)
    });


  });

  describe("Trying functionality", () => {

    test("basic database test", async ()  => {
      jest.setTimeout(10000)
      const res= await request.get('/database/')
      expect(res.status).toEqual(302)
    });

    test("login", async ()  => {
      jest.setTimeout(10000)
      const res= await request.post('/database/auth')
      .send({
        userName_: "p",
        psw : "p"
      })
      expect(res.status).toEqual(302)
    });

    test("failed login", async ()  => {
      jest.setTimeout(10000)
      const res= await request.post('/database/auth')
      .send({
        userName_: "p",
        psw : "dkjclnwjd"
      })
      
      expect(res.status).toEqual(302)
    });

    test("New registration with existing details", async ()  => {
      jest.setTimeout(10000)
      const res= await request.post('/database/add')
      .send({
        name: "p",
        psw : "p"
      })
      
      expect(res.status).toEqual(302)
    });

    test("Testing the get new data function", async ()  => {
      jest.setTimeout(10000)
      let res= await request.post('/database/auth')
      .send({
        name: "p",
        psw : "p"
      })
       res=  await request.get('/database/newdata')
      expect(res.status).toEqual(200)
    });

    test("Test list function", async ()  => {
      jest.setTimeout(10000)
      const res= await request.get('/database/list')
      
      expect(res.status).toEqual(200)
    });

    test("Change details", async ()  => {
      jest.setTimeout(10000)
      const res= await request.post('/database/changedetails').send({
        name: "p",
        surname: "p",
        username:"p",
        email:"p",
        password:"p"


      })
      
      expect(res.status).toEqual(302)
    });

    test("Change details with no details", async ()  => {
      jest.setTimeout(10000)
      const res= await request.post('/database/changedetails').send({
        name: "",
        surname: "",
        username:"",
        email:"",
        password:""


      })
      
      expect(res.status).toEqual(302)
    });

    test("test logout", async ()  => {
      jest.setTimeout(10000)
      const res= await request.post('/database/logout')
      
      expect(res.status).toEqual(302)
    });

    test(" test log", async ()  => {
      jest.setTimeout(10000)
      const res= await request.post('/database/log')
      
      expect(res.status).toEqual(200)
    });

    test("test mean ", async ()  => {
      jest.setTimeout(10000)
      const res= await request.get('/database/getMean')
      
      expect(res.status).toEqual(200)
    });

    test("get settlements ", async ()  => {
      jest.setTimeout(10000)
      const res= await request.get('/database/getMean')
      
      expect(res.status).toEqual(200)
    });

    test("Test calc owing function ", async ()  => {
      jest.setTimeout(10000)
      l=dbRouter.calcOwing(200,200)
      
      expect(l).toEqual([])
    });

    test("Test minof2 owing function ", async ()  => {
      jest.setTimeout(10000)
      l=dbRouter.minOf2(200,100)
      
      expect(l).toEqual(100)
    });

    test("add expense ", async ()  => {
      jest.setTimeout(10000)
      const res= await request.post('/database/add-expense')
      
      expect(res.status).toEqual(200)
    });


    test("Test getmax owing function ", async ()  => {
      
      l=dbRouter.getMax([5000,300,200])
      
      expect(l).toEqual(0)
    });

    test("Test getmin owing function ", async ()  => {
      
      l=dbRouter.getMin([5000,300,200])
      
      expect(l).toEqual(0)
    });





    
  });


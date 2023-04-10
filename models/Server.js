import express from "express"
import cors from 'cors'
import authLectura from "../routes/lectura.js"

export class Server{
    constructor(){
        this.app=express()
        this.port=8080
        this.routes={
            verificacion:'/api/capufe'
        }
        this.middlewares()
        this.router()
    }
    middlewares()
    {
        this.app.use(express.json())
        this.app.use(express.static('public'))
        this.app.use(cors())
    }
    router()
    {
        this.app.use(this.routes.verificacion,authLectura)
    }
    listen()
    {
        this.app.listen(this.port,()=>{
            console.log("Servidor corriendo en el puerto 8080")
        })
    }
}
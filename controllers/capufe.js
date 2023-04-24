import { response,request } from "express";



export const tokenGet=async(req,res=response)=>{
    const {qr,caseta}=req.query
    try {
        const primerParte=qr?.slice(0,12)
        let segundaParte=qr?.slice(12,13)
        segundaParte.split('').join(" ")
        segundaParte=" "+segundaParte
        const ultimoString=primerParte+segundaParte
        console.log(ultimoString)
        res.json({
            msg:"Enviado correctamente",
            qr:ultimoString,
        })
    } catch (error) {
        console.log("error")
    }
}


export const tokenPost=async(req,res=response)=>{
    const {qr}=req.body
    console.log(qr)
    res.json({
        msg:"Enviado correctamente",
        qr,
        
    })
}


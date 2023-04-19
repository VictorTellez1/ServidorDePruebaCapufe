import { response,request } from "express";



export const tokenGet=async(req,res=response)=>{
    const {token,caseta}=req.query
    const primerParte=token.slice(0,12)
    let segundaParte=token.slice(12,13)
    segundaParte.split('').join(" ")
    segundaParte=" "+segundaParte
    const ultimoString=primerParte+segundaParte
    console.log(ultimoString)
    res.json({
        msg:"Enviado correctamente",
        qr:ultimoString,
    })
}


export const tokenPost=async(req,res=response)=>{
    const {qr}=req.body
    console.log(qr)
    res.json({
        msg:"Enviado correctamente",
        qr,
        
    })
}


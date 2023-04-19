import { response,request } from "express";



export const tokenGet=async(req,res=response)=>{
    const {token,caseta}=req.query
    console.log(token)
    res.json({
        msg:"Enviado correctamente",
        token,
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


import { response,request } from "express";



export const tokenGet=async(req,res=response)=>{
    const {token}=req.query
    res.json({
        msg:"Enviado correctamente",
        token
    })
   
}


export const tokenPost=async(req,res=response)=>{
    const {token}=req.body
    res.json({
        msg:"Enviado correctamente",
        token
    })
}


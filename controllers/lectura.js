

export const lecturaDatosURL=(req,res)=>{
    const {token}=req.query
    res.json({
        msg:"Leido correctamente",
        token
    })
}

export const envioDatos=(req,res)=>{
    const {token}=req.body
    res.json({
        msg:"Enviado correctamente",
        token
    })
}
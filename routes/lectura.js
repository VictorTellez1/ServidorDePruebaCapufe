import {Router} from 'express'
import { envioDatos, lecturaDatosURL } from '../controllers/lectura.js'


const authLectura=Router()


authLectura.get('/',lecturaDatosURL)


authLectura.post('/',envioDatos)


export default authLectura
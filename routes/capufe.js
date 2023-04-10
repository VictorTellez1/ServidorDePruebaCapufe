
import { Router } from 'express';

import {tokenGet,tokenPost} from '../controllers/capufe.js'

const routerCapufe=Router()


routerCapufe.get('/', tokenGet );



routerCapufe.post('/', tokenPost );









export default routerCapufe
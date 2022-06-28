import express from 'express';
import bodyParser from 'body-parser';
import { router } from './routes';

const app = express();

app.use(express.json());
app.use(router);

export { app }; // Name export e não export default para ser mais facilmente importado e mais rápido
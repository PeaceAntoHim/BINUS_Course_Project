'use strict';
require('dotenv').config();

const {
    commentRabbitMQSubscriber,
    profileRabbitMQSubscriber,
    rabbitMQConnection,
} = require('./dependency_injection/dependency_injection');
const express = require('express');
const { router } = require('./routes/routes');
const app = express();
const port =  process.env.PORT || 3000;

// set the view engine to ejs
app.set('view engine', 'ejs');

// routes
app.use('/', router);

// start server
const server = app.listen(port);
console.log('Express started. Listening on %s', port);

commentRabbitMQSubscriber.run(rabbitMQConnection);
console.log('CommentSubscriber is up');
profileRabbitMQSubscriber.run(rabbitMQConnection);
console.log('ProfileSubscriber is up');

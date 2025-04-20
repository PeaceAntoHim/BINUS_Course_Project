const { Redis } = require('ioredis');
const { MongoClient, ServerApiVersion } = require('mongodb');
const amqplib = require('amqplib');

const getMongoClient = async function(uri, dbName) {
    const client = new MongoClient(uri);

    try {
        await client.connect();
        console.log('Connected to MongoDB server');
        
        db = client.db(dbName);
        return db;
    } catch (e) {
        console.error('Error Connecting to MongoDB: ', e);
        throw e;
    }
}

const getRedisClient = async function(host, port, password) {
    const redis = new Redis({
        host: host,         // Redis server host
        port: port,         // Redis server port
        password: password, // Password (if any)
    });
    
    // Handling connection errors
    redis.on('error', (err) => {
        console.error('Redis connection error:', err);
    });

    return redis;
}

const getRabbitMQConnection = async function(uri) {
    try {
        // Replace 'localhost' with your RabbitMQ server address if necessary
        // sample: uri = 'amqp://localhost'
        const connection = await amqplib.connect(uri); 
        // const channel = await connection.createChannel();

        return connection;
    } catch (error) {
        console.error('Error occurred:', error);
    }
}

module.exports = {
    getMongoClient,
    getRedisClient,
    getRabbitMQConnection
};

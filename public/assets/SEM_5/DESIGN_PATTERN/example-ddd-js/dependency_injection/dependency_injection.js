const { 
    getMongoClient, 
    getRedisClient, 
    getRabbitMQConnection, 
} = require('./dependency_injection.initiation');
const { ProfileCommand } = require('../src/profile/application/command/profile.command');
const { ProfileQuery } = require('../src/profile/application/query/profile.query');
const { ProfileService } = require('../src/profile/domain/profile.service');
const { ProfileNoSQLRepository } = require('../src/profile/infrastructure/repository/nosql/profile.nosql');
const { ProfileInMemoryRepository } = require('../src/profile/infrastructure/repository/inmemory/profile.inmemory');
const { ProfileRabbitMQSubscriber } = require('../src/profile/infrastructure/event/subscriber/rabbitmq/profile.rabbitmq');
const { ProfileRabbitMQPublisher } = require('../src/profile/infrastructure/event/publisher/rabbitmq/profile.rabbitmq');
const { CommentCommand } = require('../src/comment/application/command/comment.command');
const { CommentQuery } = require('../src/comment/application/query/comment.query');
const { CommentService } = require('../src/comment/domain/comment.service');
const { CommentNoSQLRepository } = require('../src/comment/infrastructure/repository/nosql/comment.nosql');
const { CommentInMemoryRepository } = require('../src/comment/infrastructure/repository/inmemory/comment.inmemory');
const { CommentRabbitMQSubscriber } = require('../src/comment/infrastructure/event/subscriber/rabbitmq/comment.rabbitmq');
const { CommentRabbitMQPublisher } = require('../src/comment/infrastructure/event/publisher/rabbitmq/comment.rabbitmq');

const redisClient = getRedisClient(process.env.REDIS_HOST, process.env.REDIS_PORT, process.env.REDIS_PASSWORD);
const mongoDB = getMongoClient(process.env.DATABASE_URL, process.env.DATABASE_NAME);
const rabbitMQConnection = getRabbitMQConnection(process.env.RABBIT_MQ_URI);

const profileInMemoryRepository = new ProfileInMemoryRepository(redisClient);
const profileNoSQLRepository = new ProfileNoSQLRepository(mongoDB);
const profileRabbitMQSubscriber = new ProfileRabbitMQSubscriber(rabbitMQConnection, profileInMemoryRepository);
const profileRabbitMQPublisher = new ProfileRabbitMQPublisher(rabbitMQConnection);
const profileInMemoryService = new ProfileService(profileInMemoryRepository, profileRabbitMQPublisher);
const profileNoSQLService = new ProfileService(profileNoSQLRepository, profileRabbitMQPublisher);
const profileCommand = new ProfileCommand(profileNoSQLService);
const profileQuery = new ProfileQuery(profileInMemoryService, profileNoSQLService);

const commentInMemoryRepository = new CommentInMemoryRepository(redisClient);
const commentNoSQLRepository = new CommentNoSQLRepository(mongoDB);
const commentRabbitMQSubscriber = new CommentRabbitMQSubscriber(rabbitMQConnection, commentInMemoryRepository);
const commentRabbitMQPublisher = new CommentRabbitMQPublisher(rabbitMQConnection);
const commentInMemoryService = new CommentService(commentInMemoryRepository, commentRabbitMQPublisher);
const commentNoSQLService = new CommentService(commentNoSQLRepository, commentRabbitMQPublisher);
const commentCommand = new CommentCommand(commentNoSQLService);
const commentQuery = new CommentQuery(commentInMemoryService, commentNoSQLService);

module.exports = {
    profileRabbitMQSubscriber,
    commentRabbitMQSubscriber,
    commentCommand,
    commentQuery,
    profileCommand,
    profileQuery,
    rabbitMQConnection,
};

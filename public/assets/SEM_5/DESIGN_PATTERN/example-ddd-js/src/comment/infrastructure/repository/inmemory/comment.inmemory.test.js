const { 
    COMMENT_REDIS_KEY, 
    COMMENT_REDIS_KEY_PREFIX_1, 
    COMMENT_REDIS_KEY_PREFIX_2, 
    ERR_NOT_FOUND, 
    CATEGORY_ALL,
    SORTED_BY_RECENT,
} = require('../../../constant/comment.constant');
const { GenericContainer, Wait } = require('testcontainers');
const { Redis } = require('ioredis');
const { CommentInMemoryRepository } = require('./comment.inmemory');

const userId = '1';
const profileId = '1';
const id = '1';
const key = COMMENT_REDIS_KEY_PREFIX_1 + '.' + userId + "." + COMMENT_REDIS_KEY_PREFIX_2 + "." + profileId + "." + COMMENT_REDIS_KEY;
const filteredBy = CATEGORY_ALL;
const sortedBy = SORTED_BY_RECENT;

function getComments() {
    var comments = new Array();
    comments.push(getComment());
    return comments;
}

function getComment() {
    return {
        id: id,
        profileId: profileId,
        userId: userId,
        comment: 'comment',
        category: 'MBTI',
        likes: 0,
    };
}

// Test suite for CommentInMemoryRepository class
describe('CommentInMemoryRepository', () => {
    let container;
    let repository;
    let redis;

    beforeEach(async () => {
        // Start a Redis container
        container = await new GenericContainer('redis')
            .withExposedPorts(6379)
            .withWaitStrategy(Wait.forListeningPorts())
            .start();

        // Get the Redis container's host and port
        const host = container.getHost();
        const port = container.getMappedPort(6379);

        redis = new Redis({
            host: host,         // Redis server host
            port: port,         // Redis server port
        });
        
        // Handling connection errors
        redis.on('error', (err) => {
            console.error('Redis connection error:', err);
        });
    

        // Initialize repository with mock Redis client pointing to the container
        repository = new CommentInMemoryRepository(redis);

        // reset redis
        redis.del(key);
    });

    // Test suite for findAll method
    describe('findAll', () => {
        it('should return comments for a given userId and profileId', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getComments()));

            // Call the method
            const result = await repository.findAll(userId, profileId, filteredBy, sortedBy);

            // Assertion
            expect(result).toEqual(getComments()); // Ensure it returns an array
            // Add more assertions as needed
        });
    });

    // Test suite for findById method
    describe('findById', () => {
        it('should return a comment for a given userId, profileId, and commentId', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getComments()));

            // Call the method
            const result = await repository.findById(userId, profileId, id);

            // Assertion
            expect(result).toEqual(getComment()); // Ensure it returns an object
            // Add more assertions as needed
        });
    });

    // Test suite for insert method
    describe('insert', () => {
        it('should insert a comment into the repository', async () => {
            // Call the method
            const result = await repository.insert(getComment());

            const actualInString = await redis.get(key);
            const actual = JSON.parse(actualInString)[0];

            // Assertion
            expect(result).toEqual(actual);
        });
    });

    // Test suite for update method
    describe('update', () => {
        it('should update a comment in the repository', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getComments()));

            var comment = getComment();
            comment.comment = 'updated comment';

            // Call the method
            const result = await repository.update(comment);

            const actualInString = await redis.get(key);
            const actual = JSON.parse(actualInString)[0];

            // Assertion
            expect(result).toEqual(actual);
        });

        it('should throw an error when comment is not found', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getComments()));

            var comment = getComment();
            comment.id = 99;
            comment.profileId = 99;
            comment.userId = 99;

            // Call the method and expect it to throw an error
            await expect(repository.update(comment)).rejects.toThrowError(ERR_NOT_FOUND);
        });
    });

    // Test suite for delete method
    describe('delete', () => {
        it('should delete a comment from the repository', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getComments()));

            var comment = getComment();

            // Call the method
            await repository.delete(comment);

            const actualInString = await redis.get(key);
            const actual = JSON.parse(actualInString);

            // Assertion
            expect(actual).toEqual(null);
        });

        it('should throw an error when comment is not found', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getComments()));

            var comment = getComment();
            comment.id = 99;
            comment.profileId = 99;
            comment.userId = 99;

            // Call the method and expect it to throw an error
            await expect(repository.delete(comment)).rejects.toThrowError(ERR_NOT_FOUND);
        });
    });
});

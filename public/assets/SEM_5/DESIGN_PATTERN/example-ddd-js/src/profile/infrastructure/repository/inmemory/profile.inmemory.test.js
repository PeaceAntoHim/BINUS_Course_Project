const { 
    PROFILE_REDIS_KEY, 
    ERR_NOT_FOUND, 
    CATEGORY_ALL,
    SORTED_BY_RECENT,
} = require('../../../constant/profile.constant');
const { GenericContainer, Wait } = require('testcontainers');
const { Redis } = require('ioredis');
const { ProfileInMemoryRepository } = require('./profile.inmemory');

const profileId = '1';
const id = '1';
const key = PROFILE_REDIS_KEY;
const filteredBy = CATEGORY_ALL;
const sortedBy = SORTED_BY_RECENT;

function getProfiles() {
    var profiles = new Array();
    profiles.push(getProfile());
    return profiles;
}

function getProfile() {
    return {
        id: id,
        profileId: profileId,
        comment: 'comment',
        category: 'MBTI',
        votes: 0,
    };
}

// Test suite for ProfileInMemoryRepository class
describe('ProfileInMemoryRepository', () => {
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
        repository = new ProfileInMemoryRepository(redis);

        // reset redis
        redis.del(key);
    });

    // Test suite for findAll method
    describe('findAll', () => {
        it('should return profiles', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getProfiles()));

            // Call the method
            const result = await repository.findAll(filteredBy, sortedBy);

            // Assertion
            expect(result).toEqual(getProfiles()); // Ensure it returns an array
            // Add more assertions as needed
        });
    });

    // Test suite for findById method
    describe('findById', () => {
        it('should return a profile for a given profileId', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getProfiles()));

            // Call the method
            const result = await repository.findById(profileId);

            // Assertion
            expect(result).toEqual(getProfile()); // Ensure it returns an object
            // Add more assertions as needed
        });
    });

    // Test suite for insert method
    describe('insert', () => {
        it('should insert a profile into the repository', async () => {
            // Call the method
            const result = await repository.insert(getProfile());

            const actualInString = await redis.get(key);
            const actual = JSON.parse(actualInString)[0];

            // Assertion
            expect(result).toEqual(actual);
        });
    });

    // Test suite for update method
    describe('update', () => {
        it('should update a profile in the repository', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getProfiles()));

            var profile = getProfile();
            profile.votes = 10;

            // Call the method
            const result = await repository.update(profile);

            const actualInString = await redis.get(key);
            const actual = JSON.parse(actualInString)[0];

            // Assertion
            expect(result).toEqual(actual);
        });

        it('should throw an error when profile is not found', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getProfiles()));

            var profile = getProfile();
            profile.id = 99;
            profile.votes = 99;
            
            // Call the method and expect it to throw an error
            await expect(repository.update(profile)).rejects.toThrowError(ERR_NOT_FOUND);
        });
    });

    // Test suite for delete method
    describe('delete', () => {
        it('should delete a profile from the repository', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getProfiles()));

            var profile = getProfile();

            // Call the method
            await repository.delete(profile);

            const actualInString = await redis.get(key);
            const actual = JSON.parse(actualInString);

            // Assertion
            expect(actual).toEqual(null);
        });

        it('should throw an error when profile is not found', async () => {
            // Insert data to redis
            redis.set(key, JSON.stringify(getProfiles()));

            var profile = getProfile();
            profile.id = 99;
            profile.votes = 99;
            
            // Call the method and expect it to throw an error
            await expect(repository.delete(profile)).rejects.toThrowError(ERR_NOT_FOUND);
        });
    });
});

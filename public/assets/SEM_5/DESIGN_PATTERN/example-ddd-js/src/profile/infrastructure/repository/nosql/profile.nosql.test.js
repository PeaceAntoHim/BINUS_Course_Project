const { MongoMemoryServer } = require('mongodb-memory-server');
const { ProfileNoSQLRepository } = require('./profile.nosql');
const { MongoClient } = require('mongodb');
const { PROFILE_MONGODB_COLLECTION_NAME } = require('../../../constant/profile.constant');

const id = '1';
const name = 'John Doe';
const filteredBy = 'All';
const sortedBy = 'recents';

function getProfile() {
  return {
      id: id,
      name: name,
  };
}

function assertComment(actual, expected) {
  expect(expected.id).toEqual(actual.id);
  expect(expected.comment).toEqual(actual.comment);
  expect(expected.likes).toEqual(actual.likes);
}

// Test suite for ProfileNoSQLRepository class
describe('ProfileNoSQLRepository', () => {
    let mongoClient;
    let db;
    let repository;
    let mongod; // Declare mongod variable for MongoDB memory server
    let collection;

    beforeEach(async () => {
        mongod = await MongoMemoryServer.create();
        uri = mongod.getUri();
        // Connect to MongoDB and initialize repository
        mongoClient = new MongoClient(uri, { useNewUrlParser: true, useUnifiedTopology: true });
        await mongoClient.connect();
        db = mongoClient.db('test'); // Use test database for testing
        collection = db.collection(PROFILE_MONGODB_COLLECTION_NAME);
        repository = new ProfileNoSQLRepository(db);
    });

    afterEach(async () => {
        // Close MongoDB connection and stop MongoDB memory server
        await mongoClient.close();
        await mongod.stop();
    });

    // Test suite for findAll method
    describe('findAll', () => {
        it('should return an array of profiles for a given userId', async () => {
            await collection.insertOne(getProfile());
            const profiles = await repository.findAll(filteredBy, sortedBy);
            assertComment(profiles[0], getProfile());
        });
    });

    // Test suite for findById method
    describe('findById', () => {
        it('should return a profile for a given userId and commentId', async () => {
            await collection.insertOne(getProfile());
            const profile = await repository.findById(id);
            assertComment(profile, getProfile());
        });
    });

    // Test suite for insert method
    describe('insert', () => {
        it('should insert a comment into the database', async () => {
            const comment = getProfile();
            const result = await repository.insert(comment);
            const actual = await collection.findOne({ _id: result._id });
            expect(result).toEqual(actual);
        });
    });

    // Test suite for update method
    describe('update', () => {
        it('should update a comment in the database', async () => {
            let baseComment = getProfile();
            await collection.insertOne(baseComment);
            
            baseComment.likes = 10;
            const result = await repository.update(baseComment);

            const actual = await collection.findOne({ id: baseComment.id });
            expect(result).toEqual(actual);
        });
    });

    // Test suite for delete method
    describe('delete', () => {
        it('should delete a comment from the database', async () => {
          let comment = getProfile();
          await collection.insertOne(comment);
          
          const result = await repository.delete(comment);

          const actual = await collection.findOne({ id: comment.id });
          expect(actual.deletedAt).toBeDefined();
        });
    });
});

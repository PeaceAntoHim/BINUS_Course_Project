const { MongoMemoryServer } = require('mongodb-memory-server');
const { CommentNoSQLRepository } = require('./comment.nosql');
const { MongoClient } = require('mongodb');
const { COMMENT_MONGODB_COLLECTION_NAME } = require('../../../constant/comment.constant');

const id = '1';
const userId = '1';
const profileId = '1';
const filteredBy = 'All';
const sortedBy = 'recents';

function getComment() {
  return {
      id: id,
      profileId: profileId,
      userId: userId,
      comment: 'comment',
      likes: 0,
      category: 'MBTI'
  };
}

function assertComment(actual, expected) {
  expect(expected.userId).toEqual(actual.userId);
  expect(expected.profileId).toEqual(actual.profileId);
  expect(expected.comment).toEqual(actual.comment);
  expect(expected.likes).toEqual(actual.likes);
}

// Test suite for CommentNoSQLRepository class
describe('CommentNoSQLRepository', () => {
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
        collection = db.collection(COMMENT_MONGODB_COLLECTION_NAME);
        repository = new CommentNoSQLRepository(db);
    });

    afterEach(async () => {
        // Close MongoDB connection and stop MongoDB memory server
        await mongoClient.close();
        await mongod.stop();
    });

    // Test suite for findAll method
    describe('findAll', () => {
        it('should return an array of comments for a given userId', async () => {
            await collection.insertOne(getComment());
            const comments = await repository.findAll(userId, profileId, filteredBy, sortedBy);
            assertComment(comments[0], getComment());
        });
    });

    // Test suite for findById method
    describe('findById', () => {
        it('should return a comment for a given userId and commentId', async () => {
            await collection.insertOne(getComment());
            const comment = await repository.findById(userId, profileId, id);
            assertComment(comment, getComment());
        });
    });

    // Test suite for insert method
    describe('insert', () => {
        it('should insert a comment into the database', async () => {
            const comment = getComment();
            const result = await repository.insert(comment);
            const actual = await collection.findOne({ _id: result._id });
            expect(result).toEqual(actual);
        });
    });

    // Test suite for update method
    describe('update', () => {
        it('should update a comment in the database', async () => {
            let baseComment = getComment();
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
          let comment = getComment();
          await collection.insertOne(comment);
          
          const result = await repository.delete(comment);

          const actual = await collection.findOne({ id: comment.id });
          expect(actual.deletedAt).toBeDefined();
        });
    });
});

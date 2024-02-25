const { CommentService } = require('./comment.service');
const { CommentRepository } = require('../infrastructure/repository/comment.repository');
const { CommentPublisher } = require('../infrastructure/event/publisher/comment.publisher');
const {
  COMMENT_CREATED_EVENT,
  COMMENT_UPDATED_EVENT,
  COMMENT_DELETED_EVENT,
} = require('../constant/comment.constant');

describe('CommentService', () => {
  let commentService;

  beforeEach(() => {
    // Create mock instances for CommentRepository and CommentPublisher
    const commentRepository = {
        insert: jest.fn(),
        update: jest.fn(),
        delete: jest.fn(),
        findAll: jest.fn(),
        find: jest.fn(),
    };
    const commentPublisher = {
        publish: jest.fn(),
    };
    // Create CommentService instance with mock dependencies
    commentService = new CommentService(commentRepository, commentPublisher);
  });

  describe('list', () => {
    it('should return an array of comments for a given user and profile', async () => {
      // Mock the behavior of repository.findAll()
      commentService.repository.findAll.mockResolvedValue([{ id: 1, text: 'Comment 1' }]);
      
      // Call the method
      const result = await commentService.list('userId', 'profileId');
      
      // Assertions
      expect(result).toEqual([{ id: 1, text: 'Comment 1' }]);
    });
  });

  describe('get', () => {
    it('should return a comment for a given user, profile, and comment id', async () => {
      // Mock the behavior of repository.find()
      commentService.repository.find.mockResolvedValue({ id: 1, text: 'Comment 1' });
      
      // Call the method
      const result = await commentService.get('userId', 'profileId', 'commentId');
      
      // Assertions
      expect(result).toEqual({ id: 1, text: 'Comment 1' });
    });
  });

  describe('add', () => {
    it('should add a comment and publish a created event', async () => {
      // Mock the behavior of repository.insert()
      commentService.repository.insert.mockResolvedValue({ id: 1, text: 'New comment' });
      
      // Mock the behavior of publisher.publish()
      commentService.publisher.publish.mockResolvedValue();
      
      // Call the method
      const result = await commentService.add({ userId: 'userId', profileId: 'profileId', text: 'New comment' });
      
      // Assertions
      expect(result).toEqual({ id: 1, text: 'New comment' });
      // Ensure publish method was called with the correct event
      expect(commentService.publisher.publish).toHaveBeenCalledWith(COMMENT_CREATED_EVENT, { id: 1, text: 'New comment' });
    });
  });

  describe('edit', () => {
    it('should edit a comment and publish an updated event', async () => {
      // Mock the behavior of repository.update()
      commentService.repository.update.mockResolvedValue({ id: 1, text: 'Updated comment' });
      
      // Mock the behavior of publisher.publish()
      commentService.publisher.publish.mockResolvedValue();
      
      // Call the method
      const result = await commentService.edit({ id: 1, userId: 'userId', profileId: 'profileId', text: 'Updated comment' });
      
      // Assertions
      expect(result).toEqual({ id: 1, text: 'Updated comment' });
      // Ensure publish method was called with the correct event
      expect(commentService.publisher.publish).toHaveBeenCalledWith(COMMENT_UPDATED_EVENT, { id: 1, text: 'Updated comment' });
    });
  });
  
  describe('remove', () => {
    it('should remove a comment and publish a deleted event', async () => {
      // Mock the behavior of repository.delete()
      commentService.repository.delete.mockResolvedValue({ id: 1, text: 'Deleted comment' });
      
      // Mock the behavior of publisher.publish()
      commentService.publisher.publish.mockResolvedValue();
      
      // Call the method
      const result = await commentService.remove({ id: 1, userId: 'userId', profileId: 'profileId' });
      
      // Assertions
      expect(result).toEqual({ id: 1, text: 'Deleted comment' });
      // Ensure publish method was called with the correct event
      expect(commentService.publisher.publish).toHaveBeenCalledWith(COMMENT_DELETED_EVENT, { id: 1, text: 'Deleted comment' });
    });
  });  
});

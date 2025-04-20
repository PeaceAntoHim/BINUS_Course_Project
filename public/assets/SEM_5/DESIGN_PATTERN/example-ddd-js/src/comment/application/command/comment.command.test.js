const { CommentCommand } = require('./comment.command');

// Mock the comment service
const commentService = {
  add: jest.fn(),
  edit: jest.fn(),
  remove: jest.fn(),
  get: jest.fn(),
};

// Create an instance of the CommentCommand class
const commentCommand = new CommentCommand(commentService);

describe('add', () => {
  it('should add a comment', async () => {
    // Mock the behavior of commentService.add()
    commentService.add.mockResolvedValue({ id: 1, text: 'New comment' });

    // Call the method
    const result = await commentCommand.add({ text: 'New comment' });

    // Assertions
    expect(result).toEqual({ id: 1, text: 'New comment' });
    expect(commentService.add).toHaveBeenCalledWith({ text: 'New comment' });
  });
});

describe('edit', () => {
  it('should edit a comment', async () => {
    // Mock the behavior of commentService.edit()
    commentService.edit.mockResolvedValue({ id: 1, text: 'Updated comment' });

    // Call the method
    const result = await commentCommand.edit({ id: 1, text: 'Updated comment' });

    // Assertions
    expect(result).toEqual({ id: 1, text: 'Updated comment' });
    expect(commentService.edit).toHaveBeenCalledWith({ id: 1, text: 'Updated comment' });
  });
});

describe('remove', () => {
  it('should remove a comment', async () => {
    // Mock the behavior of commentService.remove()
    commentService.remove.mockResolvedValue({ id: 1, text: 'Deleted comment' });

    // Call the method
    const result = await commentCommand.remove({ id: 1 });

    // Assertions
    expect(result).toEqual({ id: 1, text: 'Deleted comment' });
    expect(commentService.remove).toHaveBeenCalledWith({ id: 1 });
  });

  describe('like', () => {
    it('should like a comment', async () => {
      const userId = 1;
      const profileId = 1;
      const commentId = 1;

      // Mock the behavior of commentService.get()
      commentService.get.mockResolvedValue({ id: 1, text: 'Updated comment', likes: 0 });
      
      // Mock the behavior of commentService.edit()
      commentService.edit.mockResolvedValue({ id: 1, text: 'Updated comment', likes: 1 });
  
      // Call the method
      const result = await commentCommand.like(userId, profileId, commentId);
  
      // Assertions
      expect(result).toEqual({ id: 1, text: 'Updated comment', likes: 1 });
      expect(commentService.edit).toHaveBeenCalledWith({ id: 1, text: 'Updated comment', likes: 1 });
    });
  });

  describe('dislike', () => {
    it('should dislike a comment', async () => {
      const userId = 1;
      const profileId = 1;
      const commentId = 1;

      // Mock the behavior of commentService.get()
      commentService.get.mockResolvedValue({ id: 1, text: 'Updated comment', likes: 1 });
      
      // Mock the behavior of commentService.edit()
      commentService.edit.mockResolvedValue({ id: 1, text: 'Updated comment', likes: 0 });
  
      // Call the method
      const result = await commentCommand.dislike(userId, profileId, commentId);
  
      // Assertions
      expect(result).toEqual({ id: 1, text: 'Updated comment', likes: 0 });
      expect(commentService.edit).toHaveBeenCalledWith({ id: 1, text: 'Updated comment', likes: 0 });
    });
  });
});

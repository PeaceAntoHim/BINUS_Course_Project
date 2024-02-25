const { CommentQuery } = require('./comment.query');

// Mock the comment service and fallback service
const commentService = {
  list: jest.fn(),
  get: jest.fn(),
  add: jest.fn(),
};

const fallbackService = {
  list: jest.fn(),
  get: jest.fn(),
};

// Create an instance of the CommentQuery class
const commentQuery = new CommentQuery(commentService, fallbackService);

describe('list', () => {
  it('should return comments from primary service if available', async () => {
    // Mock the behavior of commentService.list()
    commentService.list.mockResolvedValue([{ id: 1, text: 'Comment 1' }, { id: 2, text: 'Comment 2' }]);

    // Call the method
    const result = await commentQuery.list('userId', 'profiledId', 'All', 'recents');

    // Assertions
    expect(result).toEqual([{ id: 1, text: 'Comment 1' }, { id: 2, text: 'Comment 2' }]);
    expect(commentService.list).toHaveBeenCalledWith('userId', 'profiledId', 'All', 'recents');
    expect(fallbackService.list).not.toHaveBeenCalled();
    expect(commentService.add).not.toHaveBeenCalled();
  });

  it('should return comments from fallback service if primary service returns empty result', async () => {
    // Mock the behavior of commentService.list() to return empty result
    commentService.list.mockResolvedValue([]);

    // Mock the behavior of fallbackService.list()
    fallbackService.list.mockResolvedValue([{ id: 3, text: 'Comment 3' }, { id: 4, text: 'Comment 4' }]);

    // Call the method
    const result = await commentQuery.list('userId', 'profiledId', 'All', 'recents');

    // Assertions
    expect(result).toEqual([{ id: 3, text: 'Comment 3' }, { id: 4, text: 'Comment 4' }]);
    expect(commentService.list).toHaveBeenCalledWith('userId', 'profiledId', 'All', 'recents');
    expect(fallbackService.list).toHaveBeenCalledWith('userId', 'profiledId', 'All', 'recents');
    expect(commentService.add).toHaveBeenCalledWith({ id: 3, text: 'Comment 3' });
    expect(commentService.add).toHaveBeenCalledWith({ id: 4, text: 'Comment 4' });
  });
});

describe('get', () => {
  it('should return comment from primary service if available', async () => {
    // Mock the behavior of commentService.get()
    commentService.get.mockResolvedValue({ id: 1, text: 'Comment 1' });

    // Call the method
    const result = await commentQuery.get('userId', 'profileId', 'commentId');

    // Assertions
    expect(result).toEqual({ id: 1, text: 'Comment 1' });
    expect(commentService.get).toHaveBeenCalledWith('userId', 'profileId', 'commentId');
    expect(fallbackService.get).not.toHaveBeenCalled();
  });

  it('should return comment from fallback service if primary service returns empty result', async () => {
    // Mock the behavior of commentService.get() to return empty result
    commentService.get.mockResolvedValue(null);

    // Mock the behavior of fallbackService.get()
    fallbackService.get.mockResolvedValue({ id: 2, text: 'Comment 2' });

    // Call the method
    const result = await commentQuery.get('userId', 'profileId', 'commentId');

    // Assertions
    expect(result).toEqual({ id: 2, text: 'Comment 2' });
    expect(commentService.get).toHaveBeenCalledWith('userId', 'profileId', 'commentId');
    expect(fallbackService.get).toHaveBeenCalledWith('userId', 'profileId', 'commentId');
    expect(commentService.add).toHaveBeenCalledWith({ id: 2, text: 'Comment 2' });
  });
});

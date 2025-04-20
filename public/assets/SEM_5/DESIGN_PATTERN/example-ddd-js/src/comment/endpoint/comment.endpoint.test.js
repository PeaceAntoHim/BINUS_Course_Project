const { CommentEndpoint } = require('./comment.endpoint');
const { ERR_NOT_FOUND } = require('../constant/comment.constant');
const jwt = require('jsonwebtoken');

// Mock command and query objects
const commandMock = {
  add: jest.fn(),
  edit: jest.fn(),
  remove: jest.fn(),
  like: jest.fn(),
  dislike: jest.fn(),
  get: jest.fn(),
};

const queryMock = {
  list: jest.fn(),
};

// Mock router object
const routerMock = {
  post: jest.fn(),
  put: jest.fn(),
  delete: jest.fn(),
  get: jest.fn(),
};

// Create an instance of the CommentEndpoint class
const endpoint = new CommentEndpoint(commandMock, queryMock, routerMock);
const token =  jwt.sign({ userId: 1, iat: Math.floor(Date.now() / 1000) - 30 }, 'jwt-secret-token');

describe('CommentEndpoint', () => {
  afterEach(() => {
    jest.clearAllMocks();
  });

  describe('add', () => {
    it('should add a new comment', async () => {
      // Mock request and response objects
      const req = {
        body: {
          commentNew: {
            comment: 'this is comment'
          },
        },
        headers: {
          authorization: token,
        },
        params: {
          profileId: 1,
        },
      };
      const res = {
        json: jest.fn(),
        status: jest.fn(() => res),
      };

      // Mock command add function
      commandMock.add.mockResolvedValue({/* mocked comment object */});

      // Call the method
      await endpoint.add(req, res);

      // Assertions
      expect(commandMock.add).toHaveBeenCalledWith({comment: 'this is comment', profileId: 1, userId: 1});
      expect(res.json).toHaveBeenCalledWith({});
    });

    // Add more test cases for edge cases and error handling if necessary
  });

  describe('edit', () => {
    it('should edit a comment', async () => {
      // Mock request and response objects
      const req = {
        body: {
          commentNew: {
            comment: 'this is comment'
          },
        },
        headers: {
          authorization: token,
        },
        params: {
          profileId: 1,
          commentId: 1,
        },
      };
      const res = {
        json: jest.fn(),
        status: jest.fn(() => res),
      };

      // Mock command edit function
      commandMock.edit.mockResolvedValue({/* mocked comment object */});

      // Call the method
      await endpoint.edit(req, res);

      // Assertions
      expect(commandMock.edit).toHaveBeenCalledWith({comment: 'this is comment', id: 1, userId: 1, profileId: 1});
      expect(res.json).toHaveBeenCalledWith({/* expected response */});
    });

    // Add more test cases for edge cases and error handling if necessary
  });

  describe('remove', () => {
    it('should remove a comment', async () => {
      // Mock request and response objects
      const req = {
        headers: {
          authorization: token,
        },
        params: {
          profileId: 1,
          commentId: 1,
        },
      };
      const res = {
        json: jest.fn(),
        status: jest.fn(() => res),
      };

      // Mock command remove function
      commandMock.remove.mockResolvedValue({/* mocked comment object */});

      // Call the method
      await endpoint.remove(req, res);

      // Assertions
      expect(commandMock.remove).toHaveBeenCalledWith({id: 1, profileId: 1, userId: 1});
      expect(res.json).toHaveBeenCalledWith({/* expected response */});
    });

    // Add more test cases for edge cases and error handling if necessary
  });

  describe('like', () => {
    it('should like a comment', async () => {
      // Mock request and response objects
      const req = {
        headers: {
          authorization: token,
        },
        params: {
          profileId: 1,
          commentId: 1,
        },
      };
      const res = {
        json: jest.fn(),
        status: jest.fn(() => res),
      };

      // Mock command like function
      commandMock.like.mockResolvedValue({/* mocked comment object */});

      // Call the method
      await endpoint.like(req, res);

      // Assertions
      expect(commandMock.like).toHaveBeenCalledWith(1,1,1);
      expect(res.json).toHaveBeenCalledWith({/* expected response */});
    });

    // Add more test cases for edge cases and error handling if necessary
  });

  describe('dislike', () => {
    it('should dislike a comment', async () => {
      // Mock request and response objects
      const req = {
        headers: {
          authorization: token,
        },
        params: {
          profileId: 1,
          commentId: 1,
        },
      };
      const res = {
        json: jest.fn(),
        status: jest.fn(() => res),
      };

      // Mock command dislike function
      commandMock.dislike.mockResolvedValue({/* mocked comment object */});

      // Call the method
      await endpoint.dislike(req, res);

      // Assertions
      expect(commandMock.dislike).toHaveBeenCalledWith(1,1,1);
      expect(res.json).toHaveBeenCalledWith({/* expected response */});
    });

    // Add more test cases for edge cases and error handling if necessary
  });

  describe('list', () => {
    it('should return a list of comments', async () => {
      // Mock request and response objects
      const req = {
        headers: {
          authorization: token,
        },
        params: {
          profileId: 1,
        },
        query: {
          category: 'some_category',
          sort: 'some_sort',
        },
      };
      const res = {
        json: jest.fn(),
        status: jest.fn(() => res),
      };

      // Mock query list function
      queryMock.list.mockResolvedValue([/* mocked comment objects */]);

      // Call the method
      await endpoint.list(req, res);

      // Assertions
      expect(queryMock.list).toHaveBeenCalledWith(1,1,'some_category', 'some_sort');
      expect(res.json).toHaveBeenCalledWith([/* expected response */]);
    });

    // Add more test cases for edge cases and error handling if necessary
  });

  describe('get', () => {
    it('should return a single comment', async () => {
      // Mock request and response objects
      const req = {
        headers: {
          authorization: token,
        },
        params: {
          profileId: 1,
          commentId: 1,
        },
      };
      const res = {
        json: jest.fn(),
        status: jest.fn(() => res),
      };

      // Mock command get function
      commandMock.get.mockResolvedValue({/* mocked comment object */});

      // Call the method
      await endpoint.get(req, res);

      // Assertions
      expect(commandMock.get).toHaveBeenCalledWith(1,1,1);
      expect(res.json).toHaveBeenCalledWith({/* expected response */});
    });

    // Add more test cases for edge cases and error handling if necessary
  });

  // Add similar test cases for other methods (edit, remove, like, dislike, list, get)
});

const { ProfileEndpoint } = require('./profile.endpoint');
const jwt = require('jsonwebtoken');

// Mock dependencies
const commandMock = {
    add: jest.fn().mockResolvedValue({ id: 1, name: 'John Doe', description: 'Lorem ipsum', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'image-url' }),
    edit: jest.fn().mockResolvedValue({ id: 1, name: 'John Doe', description: 'Updated description', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'updated-image-url' }),
    remove: jest.fn().mockResolvedValue({ id: 1, name: 'John Doe', description: 'Lorem ipsum', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'image-url' }),
    vote: jest.fn().mockResolvedValue({ id: 1, name: 'John Doe', description: 'Lorem ipsum', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'image-url' }),
    unvote: jest.fn().mockResolvedValue({ id: 1, name: 'John Doe', description: 'Lorem ipsum', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'image-url' }),
    
};

const queryMock = {
    get: jest.fn().mockResolvedValue({ id: 1, name: 'John Doe', description: 'Lorem ipsum', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'image-url' }),
    list: jest.fn().mockResolvedValue([{ id: 1, name: 'John Doe', description: 'Lorem ipsum', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'image-url' }])
};

// Mock router
const routerMock = {
    put: jest.fn(),
    delete: jest.fn(),
    post: jest.fn(),
    get: jest.fn()
};

// Create instance of ProfileEndpoint
const profileEndpoint = new ProfileEndpoint(commandMock, queryMock, routerMock);
const token =  jwt.sign({ userId: 1, iat: Math.floor(Date.now() / 1000) - 30 }, 'jwt-secret-token');

describe('ProfileEndpoint', () => {
    describe('add', () => {
        it('should add a new profile', async () => {
            // Mock request and response objects
            const req = {
                body: {
                    profileNew: {
                        name: 'John Doe',
                        description: 'Lorem ipsum',
                        mbti: 'INFP',
                        enneagram: '4',
                        variant: 'sx/so',
                        tritype: '479',
                        socionics: 'EII',
                        sloan: 'RCOAI',
                        psyche: 'Pyramid',
                        image: 'image-url'
                    }
                },
                headers: {
                    authorization: token
                }
            };
            const res = {
                json: jest.fn(),
                status: jest.fn().mockReturnThis()
            };

            // Call the method
            await profileEndpoint.add(req, res);

            // Assertions
            expect(commandMock.add).toHaveBeenCalledWith({
                userId: expect.any(Number),
                name: 'John Doe',
                description: 'Lorem ipsum',
                mbti: 'INFP',
                enneagram: '4',
                variant: 'sx/so',
                tritype: '479',
                socionics: 'EII',
                sloan: 'RCOAI',
                psyche: 'Pyramid',
                image: 'image-url'
            });
            expect(res.json).toHaveBeenCalledWith({ id: 1, name: 'John Doe', description: 'Lorem ipsum', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'image-url' });
        });
    });

    describe('edit', () => {
        it('should edit an existing profile', async () => {
            // Mock request and response objects
            const req = {
                body: {
                    profileNew: {
                        name: 'John Doe',
                        description: 'Updated description',
                        mbti: 'INFP',
                        enneagram: '4',
                        variant: 'sx/so',
                        tritype: '479',
                        socionics: 'EII',
                        sloan: 'RCOAI',
                        psyche: 'Pyramid',
                        image: 'updated-image-url'
                    }
                },
                headers: {
                    authorization: token
                },
                params: {
                    id: 1
                }
            };
            const res = {
                json: jest.fn(),
                status: jest.fn().mockReturnThis()
            };

            // Call the method
            await profileEndpoint.edit(req, res);

            // Assertions
            expect(commandMock.edit).toHaveBeenCalledWith({
                id: 1,
                userId: expect.any(Number),
                name: 'John Doe',
                description: 'Updated description',
                mbti: 'INFP',
                enneagram: '4',
                variant: 'sx/so',
                tritype: '479',
                socionics: 'EII',
                sloan: 'RCOAI',
                psyche: 'Pyramid',
                image: 'updated-image-url'
            });
            expect(res.json).toHaveBeenCalledWith({ id: 1, name: 'John Doe', description: 'Updated description', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'updated-image-url' });
        });
    });

    describe('remove', () => {
        it('should remove an existing profile', async () => {
            // Mock request and response objects
            const req = {
                headers: {
                    authorization: token
                },
                params: {
                    id: 1
                }
            };
            const res = {
                json: jest.fn(),
                status: jest.fn().mockReturnThis()
            };

            // Call the method
            await profileEndpoint.remove(req, res);

            // Assertions
            expect(commandMock.remove).toHaveBeenCalledWith({
                id: 1,
                userId: expect.any(Number)
            });
            expect(res.json).toHaveBeenCalledWith({ id: 1, name: 'John Doe', description: 'Lorem ipsum', mbti: 'INFP', enneagram: '4', variant: 'sx/so', tritype: '479', socionics: 'EII', sloan: 'RCOAI', psyche: 'Pyramid', image: 'image-url' });
        });
    });

    describe('vote', () => {
        it('should vote for a profile', async () => {
          // Mock request
          const req = {
            headers: {
              authorization: token,
            },
            params: {
              id: 1,
            },
            body: {
              newVote: {
                vote: 'INFP',
                category: 'mbti',
              },
            },
          };
    
          // Mock response
          const res = {
            json: jest.fn(),
            status: jest.fn(() => res),
          };
    
          // Mock command vote function
          commandMock.vote.mockResolvedValue({/* mocked profile object */});
    
          // Call the method
          await profileEndpoint.vote(req, res);
    
          // Assertions
          expect(commandMock.vote).toHaveBeenCalledWith(1, 1, 'INFP', 'mbti');
          expect(res.json).toHaveBeenCalledWith({});
        });
      });

      describe('unvote', () => {
        it('should unvote for a profile', async () => {
          // Mock request
          const req = {
            headers: {
              authorization: token,
            },
            params: {
              id: 1,
            },
            body: {
              newVote: {
                vote: 'INFP',
                category: 'mbti',
              },
            },
          };
    
          // Mock response
          const res = {
            json: jest.fn(),
            status: jest.fn(() => res),
          };
    
          // Mock command vote function
          commandMock.unvote.mockResolvedValue({/* mocked profile object */});
    
          // Call the method
          await profileEndpoint.unvote(req, res);
    
          // Assertions
          expect(commandMock.unvote).toHaveBeenCalledWith(1, 1, 'INFP', 'mbti');
          expect(res.json).toHaveBeenCalledWith({});
        });
      });

    describe('get', () => {
        // Write test for get method
    });

    describe('list', () => {
        it('should return a list of profiles', async () => {
          // Mock request
          const req = {
            headers: {
              authorization: token,
            },
            query: {
              category: 'mbti',
              sort: 'recents',
            },
          };
    
          // Mock response
          const res = {
            json: jest.fn(),
            status: jest.fn(() => res),
          };
    
          // Mock query list function
          queryMock.list.mockResolvedValue([{/* mocked profile object */}, {/* mocked profile object */}]);
    
          // Call the method
          await profileEndpoint.list(req, res);
    
          // Assertions
          expect(queryMock.list).toHaveBeenCalledWith('mbti', 'recents');
          expect(res.json).toHaveBeenCalledWith([{/* expected response */}, {}]);
        });
      });
    
      describe('get', () => {
        it('should return a specific profile', async () => {
          // Mock request
          const req = {
            headers: {
              authorization: token,
            },
            params: {
              id: 1,
            },
          };
    
          // Mock response
          const res = {
            json: jest.fn(),
            status: jest.fn(() => res),
          };
    
          // Mock command get function
          queryMock.get.mockResolvedValue({/* mocked profile object */});
    
          // Call the method
          await profileEndpoint.get(req, res);
    
          // Assertions
          expect(queryMock.get).toHaveBeenCalledWith(1);
          expect(res.json).toHaveBeenCalledWith({});
        });
      });
});

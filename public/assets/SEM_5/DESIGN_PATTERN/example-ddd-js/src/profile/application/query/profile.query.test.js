const { ProfileQuery } = require('./profile.query');

// Mock the profile service and fallback service
const profileService = {
  list: jest.fn(),
  get: jest.fn(),
  add: jest.fn(),
};

const fallbackService = {
  list: jest.fn(),
  get: jest.fn(),
};

// Create an instance of the ProfileQuery class
const profileQuery = new ProfileQuery(profileService, fallbackService);

describe('list', () => {
  it('should return profiles from primary service if available', async () => {
    // Mock the behavior of profileService.list()
    profileService.list.mockResolvedValue([{ id: 1, name: 'John Doe' }, { id: 2, name: 'Anne Hathaway' }]);

    // Call the method
    const result = await profileQuery.list('All', 'recents');

    // Assertions
    expect(result).toEqual([{ id: 1, name: 'John Doe' }, { id: 2, name: 'Anne Hathaway' }]);
    expect(profileService.list).toHaveBeenCalledWith('All', 'recents');
    expect(fallbackService.list).not.toHaveBeenCalled();
    expect(profileService.add).not.toHaveBeenCalled();
  });

  it('should return profiles from fallback service if primary service returns empty result', async () => {
    // Mock the behavior of profileService.list() to return empty result
    profileService.list.mockResolvedValue([]);

    // Mock the behavior of fallbackService.list()
    fallbackService.list.mockResolvedValue([{ id: 3, name: 'John Doe' }, { id: 4, name: 'Jane Doe' }]);

    // Call the method
    const result = await profileQuery.list('All', 'recents');

    // Assertions
    expect(result).toEqual([{ id: 3, name: 'John Doe' }, { id: 4, name: 'Jane Doe' }]);
    expect(profileService.list).toHaveBeenCalledWith('All', 'recents');
    expect(fallbackService.list).toHaveBeenCalledWith('All', 'recents');
    expect(profileService.add).toHaveBeenCalledWith({ id: 3, name: 'John Doe' });
    expect(profileService.add).toHaveBeenCalledWith({ id: 4, name: 'Jane Doe' });
  });
});

describe('get', () => {
  it('should return profile from primary service if available', async () => {
    // Mock the behavior of profileService.get()
    profileService.get.mockResolvedValue({ id: 1, name: 'John Doe' });

    // Call the method
    const result = await profileQuery.get('profileId');

    // Assertions
    expect(result).toEqual({ id: 1, name: 'John Doe' });
    expect(profileService.get).toHaveBeenCalledWith('profileId');
    expect(fallbackService.get).not.toHaveBeenCalled();
  });

  it('should return profile from fallback service if primary service returns empty result', async () => {
    // Mock the behavior of profileService.get() to return empty result
    profileService.get.mockResolvedValue(null);

    // Mock the behavior of fallbackService.get()
    fallbackService.get.mockResolvedValue({ id: 2, name: 'John Doe' });

    // Call the method
    const result = await profileQuery.get('profileId');

    // Assertions
    expect(result).toEqual({ id: 2, name: 'John Doe' });
    expect(profileService.get).toHaveBeenCalledWith('profileId');
    expect(fallbackService.get).toHaveBeenCalledWith('profileId');
    expect(profileService.add).toHaveBeenCalledWith({ id: 2, name: 'John Doe' });
  });
});

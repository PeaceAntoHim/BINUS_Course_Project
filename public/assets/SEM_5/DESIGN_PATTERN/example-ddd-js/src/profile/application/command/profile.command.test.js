const { ProfileCommand } = require('./profile.command');

// Mock the profile service
const profileService = {
  add: jest.fn(),
  edit: jest.fn(),
  remove: jest.fn(),
  get: jest.fn(),
};

// Create an instance of the ProfileCommand class
const profileCommand = new ProfileCommand(profileService);

describe('add', () => {
  it('should add a profile', async () => {
    // Mock the behavior of profileService.add()
    profileService.add.mockResolvedValue({ id: 1, name: 'John Doe' });

    // Call the method
    const result = await profileCommand.add({ name: 'John Doe' });

    // Assertions
    expect(result).toEqual({ id: 1, name: 'John Doe' });
    expect(profileService.add).toHaveBeenCalledWith({ name: 'John Doe' });
  });
});

describe('edit', () => {
  it('should edit a profile', async () => {
    // Mock the behavior of profileService.edit()
    profileService.edit.mockResolvedValue({ id: 1, name: 'John Doe' });

    // Call the method
    const result = await profileCommand.edit({ id: 1, name: 'John Doe' });

    // Assertions
    expect(result).toEqual({ id: 1, name: 'John Doe' });
    expect(profileService.edit).toHaveBeenCalledWith({ id: 1, name: 'John Doe' });
  });
});

describe('remove', () => {
  it('should remove a profile', async () => {
    // Mock the behavior of profileService.remove()
    profileService.remove.mockResolvedValue({ id: 1, name: 'John Doe' });

    // Call the method
    const result = await profileCommand.remove({ id: 1 });

    // Assertions
    expect(result).toEqual({ id: 1, name: 'John Doe' });
    expect(profileService.remove).toHaveBeenCalledWith({ id: 1 });
  });

  describe('vote', () => {
    it('should vote a profile', async () => {
      const userId = 1;
      const profileId = 1;
      
      let votes = [];
      votes['mbti'] = [];
      votes['mbti'] = [{vote:'INFP', userId: 1}, {vote:'INTJ', userId: 1}];
      // Mock the behavior of profileService.get()
      profileService.get.mockResolvedValue({ id: 1, name: 'John Doe', votes: votes });
      
      // Mock the behavior of profileService.edit()
      votes['mbti'].push({vote:'ENTP', userId: 1});
      profileService.edit.mockResolvedValue({ id: 1, name: 'John Doe', votes: votes });
  
      // Call the method
      const result = await profileCommand.vote(userId, profileId, 'ENTP', 'mbti');
  
      // Assertions
      expect(result).toEqual({ id: 1, name: 'John Doe', votes: votes });
      expect(profileService.edit).toHaveBeenCalledWith({ id: 1, name: 'John Doe', votes: votes });
    });
  });

  describe('unvote', () => {
    it('should unvote a profile', async () => {
      const userId = 1;
      const profileId = 1;

      // Mock the behavior of profileService.get()
      let votes = [];
      votes['mbti'] = [];
      votes['mbti'].push([{vote:'INFP', userId: 1}, {vote:'INTJ', userId: 1}, {vote:'ENTP', userId: 1}]);
      profileService.get.mockResolvedValue({ id: 1, name: 'John Doe', votes: votes });
      
      // Mock the behavior of profileService.edit()
      let finalVotes = [];
      finalVotes['mbti'] = votes['mbti'].filter((vote) => vote.vote !== 'ENTP' || vote.userId !== userId);
      profileService.edit.mockResolvedValue({ id: 1, name: 'John Doe', votes: finalVotes });
  
      // Call the method
      const result = await profileCommand.unvote(userId, profileId, 'ENTP', 'mbti');
  
      // Assertions
      expect(result).toEqual({ id: 1, name: 'John Doe', votes: finalVotes });
      expect(profileService.edit).toHaveBeenCalledWith({ id: 1, name: 'John Doe', votes: finalVotes });
    });
  });
});

const { ProfileService } = require('./profile.service');
const { ProfileRepository } = require('../infrastructure/repository/profile.repository');
const { ProfilePublisher } = require('../infrastructure/event/publisher/profile.publisher');
const {
  PROFILE_CREATED_EVENT,
  PROFILE_UPDATED_EVENT,
  PROFILE_DELETED_EVENT,
} = require('../constant/profile.constant');

describe('ProfileService', () => {
  let profileService;

  beforeEach(() => {
    // Create mock instances for ProfileRepository and ProfilePublisher
    const profileRepository = {
        insert: jest.fn(),
        update: jest.fn(),
        delete: jest.fn(),
        findAll: jest.fn(),
        find: jest.fn(),
    };
    const profilePublisher = {
        publish: jest.fn(),
    };
    // Create ProfileService instance with mock dependencies
    profileService = new ProfileService(profileRepository, profilePublisher);
  });

  describe('list', () => {
    it('should return an array of profiles', async () => {
      // Mock the behavior of repository.findAll()
      profileService.repository.findAll.mockResolvedValue([{ id: 1, name: 'John Doe' }]);
      
      // Call the method
      const result = await profileService.list('mbti', 'recents');
      
      // Assertions
      expect(result).toEqual([{ id: 1, name: 'John Doe' }]);
    });
  });

  describe('get', () => {
    it('should return a profile for a given id', async () => {
      // Mock the behavior of repository.find()
      profileService.repository.find.mockResolvedValue({ id: 1, name: 'John Doe' });
      
      // Call the method
      const result = await profileService.get(1);
      
      // Assertions
      expect(result).toEqual({ id: 1, name: 'John Doe' });
    });
  });

  describe('add', () => {
    it('should add a profile and publish a created event', async () => {
      // Mock the behavior of repository.insert()
      profileService.repository.insert.mockResolvedValue({ id: 1, name: 'John Doe' });
      
      // Mock the behavior of publisher.publish()
      profileService.publisher.publish.mockResolvedValue();
      
      // Call the method
      const result = await profileService.add({ name: 'John Doe' });
      
      // Assertions
      expect(result).toEqual({ id: 1, name: 'John Doe' });
      // Ensure publish method was called with the correct event
      expect(profileService.publisher.publish).toHaveBeenCalledWith(PROFILE_CREATED_EVENT, { id: 1, name: 'John Doe' });
    });
  });

  describe('edit', () => {
    it('should edit a profile and publish an updated event', async () => {
      // Mock the behavior of repository.update()
      profileService.repository.update.mockResolvedValue({ id: 1, name: 'Jonathan Albert' });
      
      // Mock the behavior of publisher.publish()
      profileService.publisher.publish.mockResolvedValue();
      
      // Call the method
      const result = await profileService.edit({ id: 1, name: 'Jonathan Albert' });
      
      // Assertions
      expect(result).toEqual({ id: 1, name: 'Jonathan Albert' });
      // Ensure publish method was called with the correct event
      expect(profileService.publisher.publish).toHaveBeenCalledWith(PROFILE_UPDATED_EVENT, { id: 1, name: 'Jonathan Albert' });
    });
  });
  
  describe('remove', () => {
    it('should remove a profile and publish a deleted event', async () => {
      // Mock the behavior of repository.delete()
      profileService.repository.delete.mockResolvedValue({ id: 1, name: 'John Doe' });
      
      // Mock the behavior of publisher.publish()
      profileService.publisher.publish.mockResolvedValue();
      
      // Call the method
      const result = await profileService.remove({ id: 1, name: 'John Doe' });
      
      // Assertions
      expect(result).toEqual({ id: 1, name: 'John Doe' });
      // Ensure publish method was called with the correct event
      expect(profileService.publisher.publish).toHaveBeenCalledWith(PROFILE_DELETED_EVENT, { id: 1, name: 'John Doe' });
    });
  });  
});

#pragma once
#include <map>
#include <mutex>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

typedef std::map<std::string, sf::Texture> Textures;
typedef std::map<std::string, sf::Font> Fonts;
typedef std::map<std::string, sf::Sound> Sounds;
typedef std::map<std::string, sf::SoundBuffer> SoundBuffers;
typedef std::map<std::string, sf::Image> Icons;

class AssetManager
{
public:
	~AssetManager();

	static AssetManager* getInstance();

	void LoadTexture(const std::string&, const std::string&);
	sf::Texture& GetTexture(const std::string&);

	void LoadFont(const std::string&, const std::string&);
	sf::Font& GetFont(const std::string&);

	void LoadSound(const std::string&, const std::string&);
	void PlaySound(const std::string&);

	void LoadIcon(const std::string&, const std::string&);
	sf::Image& GetIcon(const std::string&);
private:
	AssetManager() = default;

	static AssetManager* _instance;
	Textures _textures;
	Fonts _fonts;
	SoundBuffers _buffers;
	Sounds _sounds;
	Icons _icons;
	std::mutex _mutex;
};

extern AssetManager* const assetManager;
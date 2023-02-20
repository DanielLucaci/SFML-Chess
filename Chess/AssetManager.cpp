#include "AssetManager.h"
#include <iostream>

void AssetManager::LoadTexture(const std::string& name, const std::string& filepath) {
	sf::Texture tex;
	if (!tex.loadFromFile(filepath)) {
		std::cerr << "Error reading image " << filepath << ". Image not found\n";
	}
	this->_textures[name] = tex;
}

void AssetManager::LoadFont(const std::string& name, const std::string& filepath) {
	sf::Font font;
	if (font.loadFromFile(filepath)) {
		this->_fonts[name] = font;
	}
}

void AssetManager::LoadSound(const std::string& name, const std::string& filepath) {
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile(filepath)) {
		this->_buffers[name] = buffer;
		this->_sounds[name] = sf::Sound(this->_buffers[name]);
	}
}

void AssetManager::LoadIcon(const std::string& name, const std::string& filepath) {
	sf::Image icon;
	if (icon.loadFromFile(filepath)) {
		this->_icons[name] = icon;
	}
}

sf::Font& AssetManager::GetFont(const std::string& name) {
	return this->_fonts.at(name);
}

sf::Texture& AssetManager::GetTexture(const std::string& name) {
	return this->_textures.at(name);
}

void AssetManager::PlaySound(const std::string& name) {
	this->_sounds.at(name).play();
}

sf::Image& AssetManager::GetIcon(const std::string& name) {
	return this->_icons.at(name);
}



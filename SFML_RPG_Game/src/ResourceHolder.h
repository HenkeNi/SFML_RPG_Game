#pragma once

#include <map>
#include <memory>
#include <string>

// Forward declarations 
class sf::Texture;
class sf::Font;


template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void load(Identifier id, const std::string& filename);

	template <typename Param>
	void load(Identifier id, const std::string& filename, const Param& param);

	Resource&		getResource(Identifier id);
	const Resource& getResource(Identifier id) const;

private:
	void insertResource(Identifier id, std::unique_ptr<Resource> resource);

private:
	std::map<Identifier, std::unique_ptr<Resource>> m_resourceMap;
};

#include "ResourceHolder.inl"


using TextureHolder_t = ResourceHolder<sf::Texture, std::string>;
using FontHolder_t	  = ResourceHolder<sf::Font, std::string>;
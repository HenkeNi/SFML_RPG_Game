 #include "ResourceHolder.h"

#include <cassert>
#include <stdexcept>


// Loads resource from file
template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	auto resource{ std::make_unique<Resource>() };
	if (!resource->loadFromFile(filename))
		throw std::runtime_error("Failed to load Resource: " + filename);

	// insert Resource to map on success
	insertResource(id, std::move(resource));
}


template <typename Resource, typename Identifier>
template <typename Param>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Param& param)
{
	auto resource{ std::make_unique<Resource>() };
	if (!resource->loadFromFile(filename, param))
		throw std::runtime_error("Failed to load Resource (with param): " + filename);

	// insert Resource to map on success
	insertResource(id, std::move(resource));
}


template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::getResource(Identifier id)
{
	auto found{ m_resourceMap.find(id) };
	assert(found != m_resourceMap.end());

	return *found->second;
}


template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::getResource(Identifier id) const
{
	auto found{ m_resourceMap.find(id) };
	assert(found != m_resourceMap.end());

	return *found->second;
}


template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource)
{
	auto inserted{ m_resourceMap.insert(std::make_pair(id, std::move(resource))) };
	assert(inserted.second);
}

#pragma once

#include <map>
#include <memory>
#include <string>

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
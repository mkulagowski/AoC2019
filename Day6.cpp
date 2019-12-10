#include<string>
#include<vector>
#include "InputManager.hpp"
#include <unordered_map>
#include <memory>
#include <iostream>


class GraphNode
{
	std::shared_ptr<GraphNode> mParent;
	std::vector<std::shared_ptr<GraphNode>> mChildren;
	std::string mName;

public:
	GraphNode(const std::string& name)
		: mName(name)
		, mParent(nullptr)
	{}

	GraphNode(const std::string& name, std::shared_ptr<GraphNode> parent)
		: mName(name)
		, mParent(parent)
	{}

	std::shared_ptr<GraphNode> getParent()
	{
		return mParent;
	}

	std::vector<std::shared_ptr<GraphNode>>& getChildren()
	{
		return mChildren;
	}

	const std::string& getName() const
	{
		return mName;
	}

	void addChild(std::shared_ptr<GraphNode> node)
	{
		mChildren.push_back(node);
	}

	void setParent(std::shared_ptr<GraphNode> node)
	{
		mParent = node;
	}

	int countDepth()
	{
		if (!mParent)
			return 0;
		else
			return 1 + mParent->countDepth();
	}

	int findNode(const std::string& name, const std::string& skip)
	{
		if (mName.compare(name) == 0)
		{
			return 1;
		}
		else {
			for (const auto& c : mChildren)
			{
				if (c->getName().compare(skip) != 0)
				{
					int ret = c->findNode(name, mName);
					if (ret > 0)
						return ret + 1;
				}
			}
			if (mParent->getName().compare(skip) != 0)
			{
				int ret = mParent->findNode(name, mName);
				if (ret > 0)
					return ret + 1;
			}
		}
		return 0;
	}

	bool operator==(const GraphNode& other) const
	{
		return mName.compare(other.mName) == 0;
	}
};

namespace std {
	template <>
	struct hash<GraphNode>
	{
		std::size_t operator()(const GraphNode& k) const
		{
			return std::hash<std::string>()(k.getName());
		}
	};
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch) && ch != '\0';
		}).base(), s.end());
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
	rtrim(s);
	return s;
}

class OrbitSolver
{
	std::vector<std::string> mMemory;
	std::unordered_map<std::string, std::shared_ptr<GraphNode>> orbitMap;

public:
	void initializeMemory(const std::string& input)
	{
		mMemory = InputManager::splitString<'\n'>(input);
		std::vector<std::string> rootStr = InputManager::splitString<')'>(mMemory[0]);
		std::shared_ptr<GraphNode> root = std::make_shared<GraphNode>(rootStr[0]);
		orbitMap.emplace(root->getName(), root);
		for (std::string str : mMemory)
		{
			std::vector<std::string> obss = InputManager::splitString<')'>(str);
			const std::string& nodeName = obss[0];
			const std::string& childName = rtrim_copy(obss[1]);
			if (orbitMap.contains(nodeName))
			{
				std::shared_ptr<GraphNode> node = orbitMap[nodeName];
				if (orbitMap.contains(childName))
				{
					std::shared_ptr<GraphNode> childNode = orbitMap[childName];
					childNode->setParent(node);
					node->addChild(childNode);
				}
				else
				{
					std::shared_ptr<GraphNode> childNode = std::make_shared<GraphNode>(childName, node);
					orbitMap.emplace(childName, childNode);
					node->addChild(childNode);
				}
			}
			else {
				if (orbitMap.contains(childName))
				{
					std::shared_ptr<GraphNode> childNode = orbitMap[childName];
					std::shared_ptr<GraphNode> node = std::make_shared<GraphNode>(nodeName);
					orbitMap.emplace(nodeName, node);
					childNode->setParent(node);
					node->addChild(childNode);
				}
				else
				{
					std::shared_ptr<GraphNode> node = std::make_shared<GraphNode>(nodeName);
					orbitMap.emplace(nodeName, node);
					std::shared_ptr<GraphNode> childNode = std::make_shared<GraphNode>(childName, node);
					orbitMap.emplace(childName, childNode);
					node->addChild(childNode);
				}
			}
		}
	}

	void countOrbits()
	{
		int totalOrbits = 0;
		for (const auto& n : orbitMap)
		{
			int ct = n.second->countDepth();
			std::cout << "Counting " << n.first << "=" << ct << std::endl;
			totalOrbits += ct;
		}
		std::cout << "Total orbits: " << totalOrbits << std::endl;
	}

	void countPathLength()
	{
		std::shared_ptr<GraphNode> myOrbit = orbitMap["YOU"]->getParent();
		std::shared_ptr<GraphNode> santaOrbit = orbitMap["SAN"]->getParent();
		int path = myOrbit->findNode(santaOrbit->getName(), "YOU") - 1;
		std::cout << "The path is " << path << std::endl;
	}
};
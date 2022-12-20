/*
** EPITECH PROJECT, 2022
** DuckHunt
** File description:
** AssetsMap
*/

#ifndef ASSETSMAP_HPP_
#define ASSETSMAP_HPP_

#include <ecstasy/resources/Resource.hpp>
#include <string>
#include <string_view>
#include <unordered_map>

namespace sf
{
    class Texture;
} // namespace sf

/// Map used to store assets (fonts, textures...) with strings as keys.
///
/// @tparam T type of the assets to store.
template <typename T>
class AssetMap : public ecstasy::Resource {
  public:
    /// Default constructor.
    AssetMap()
    {
    }

    /// Destructor, call @c clear.
    ~AssetMap()
    {
        clear();
    }

    /// Add an asset by copy, prefer use @ref emplace() when possible.
    ///
    /// @param name name of the asset.
    /// @param asset value of the asset.
    void add(const std::string &name, const T &asset)
    {
        _assets[name] = asset;
    }

    /// Add a new asset in the map.
    ///
    /// @param name asset name.
    /// @param args arguments that will be passed to the asset's constructor.
    /// @return T& created asset.
    template <typename... Args>
    T &emplace(const std::string &name, Args &&...args)
    {
        return _assets
            .emplace(std::piecewise_construct, std::forward_as_tuple(name),
                std::forward_as_tuple(std::forward<Args>(args)...))
            .first->second;
    }

    /// Access to an asset stored in the map.
    ///
    /// @param name name of the asset.
    /// @return const T& reference to the asset.
    /// @throw std::out_of_range If there is no asset matching @c name in the map.
    const T &get(const std::string &name) const
    {
        return _assets.at(name);
    }

    /// Access to an asset stored in the map.
    ///
    /// @param name name of the asset.
    /// @return T& reference to the asset.
    /// @throw std::out_of_range If there is no asset matching @c name in the map.
    T &get(const std::string &name)
    {
        return _assets.at(name);
    }

    /// Clear the asset map.
    void clear(void)
    {
        _assets.clear();
    }

    /// Get the number of assets registered.
    ///
    /// @return size_t number of assets registered.
    size_t getSize() const
    {
        return _assets.size();
    }

  private:
    std::unordered_map<std::string, T> _assets;
};

using Textures = AssetMap<sf::Texture>;

#endif /* !ASSETSMAP_HPP_ */

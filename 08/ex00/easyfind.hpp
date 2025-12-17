/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:58:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/12/17 07:47:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

/**
 * @brief Find the index of val in the container
 *
 * @tparam T
 * @param container
 * @param val
 * @return int
 * @note Why const T& container?
 * A: only search, not modified, supports const containers.
 *
 */
template <typename T>
int easyfind(const T& container, int val) {
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), val);
    if (it == container.end()) throw std::exception();
    return std::distance(container.begin(), it);
}

#endif
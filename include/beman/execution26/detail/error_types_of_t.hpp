// include/beman/execution26/detail/error_types_of_t.hpp              -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef INCLUDED_BEMAN_EXECUTION26_DETAIL_ERROR_TYPES_OF
#define INCLUDED_BEMAN_EXECUTION26_DETAIL_ERROR_TYPES_OF

#include <beman/execution26/detail/completion_signatures_of_t.hpp>
#include <beman/execution26/detail/empty_env.hpp>
#include <beman/execution26/detail/gather_signatures.hpp>
#include <beman/execution26/detail/set_error.hpp>
#include <beman/execution26/detail/variant_or_empty.hpp>
#include <type_traits>

// ----------------------------------------------------------------------------

namespace beman::execution26
{
    template <typename Sender,
              typename Env = ::beman::execution26::empty_env,
              template <typename...> class Variant = ::beman::execution26::detail::variant_or_empty>
    using error_types_of_t
        = ::beman::execution26::detail::gather_signatures<
            ::beman::execution26::set_error_t,
            ::beman::execution26::completion_signatures_of_t<Sender, Env>,
            ::std::type_identity_t,
            Variant
        >;
}

// ----------------------------------------------------------------------------

#endif

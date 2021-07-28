#ifndef __GRPCSERVERINFO_H__
#define __GRPCSERVERINFO_H__

#include <string_view>

namespace HyperNovaLabs::Native::Backend
{
  class GrpcServerInfo
  {
  public:
    static inline constexpr std::string_view ServerAddress = "0.0.0.0:50051";
  };
} // namespace HyperNovaLabs::Native::Backend

#endif // __GRPCSERVERINFO_H__
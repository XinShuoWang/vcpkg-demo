#include <cstdint>
#include <folly/compression/Compression.h>
#include <folly/compression/Zstd.h>
#include <folly/io/IOBuf.h>
#include <fstream>
#include <iostream>

int main() {
  const int32_t kFileSize = 111176946;
  const int32_t kCompressionLevel = 3;
  const std::string kFileName = "before-compress-write-111176946.bin";
  std::unique_ptr<folly::io::Codec> codec =
      folly::io::zstd::getCodec(folly::io::zstd::Options(kCompressionLevel));
  std::unique_ptr<folly::IOBuf> ioBuf = folly::IOBuf::create(kFileSize);
  std::ifstream file(kFileName, std::ios::binary);
  auto content = file.rdbuf();
  auto ans = content->sgetn(reinterpret_cast<char *>(ioBuf->writableData()),
                            kFileSize);
  auto compressed = codec->compress(ioBuf.get());
  std::cout << compressed->length() << "," << ans << std::endl;
  return 0;
}

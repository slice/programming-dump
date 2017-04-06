#include <fstream>
#include <iostream>
#include <cstring>

using std::string;

string key = "ABL4QXYZ{;^%%$$";

bool ends_with(const string& value, const string& ending) {
  if (ending.size() > value.size()) return false;
  return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

string slurp(const string& file_name) {
  std::ifstream stream{ file_name, std::ios::binary | std::ios::ate };
  auto size = stream.tellg();
  string buf(size, '\0');
  stream.seekg(0);
  stream.read(&buf[0], size);
  return buf;
}

void process_file(
    const string& key, const string& file_name, const string& output_file_name) {
  string file_contents = slurp(file_name);
  string encrypted_buf(file_contents.length(), '\0');

  for (unsigned int i = 0; i != file_contents.length(); i++) {
    int index = i % key.length();
    char key_singled = key[index];
    encrypted_buf[i] = file_contents[i] ^ key_singled;
  }

  std::ofstream out(output_file_name);
  out.write(&encrypted_buf[0], encrypted_buf.length());

  std::cout << "done\n";
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "err: not enough args\n";
    std::abort();
  }

  std::string file_name(argv[1]);

  if (ends_with(file_name, ".encrypted")) {
    process_file(key, file_name, file_name + ".decrypted");
  } else {
    process_file(key, file_name, file_name + ".encrypted");
  }
}

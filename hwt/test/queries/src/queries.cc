#include <iostream>
#include <vector>
#include <chrono>

#include "ranged_set.hpp"

#ifdef BOOST_FOUND__
#include <boost/program_options.hpp>
#include <boost/program_options/option.hpp>
namespace po = boost::program_options;
#endif

int main(int argc, char *argv[]) {
  if (!std::cin || !std::cout) {
    std::abort();
  }

#ifdef BOOST_FOUND__
  po::options_description desc("Available options");
  desc.add_options()("help,h", "Print this help message")("count-time,t", "Print perfomance metrics");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << "\n";
    return 1;
  }
#endif

  throttle::ranged_set<int> s{};
  s.insert(1);
  s.insert(2);
  s.insert(5);
  s.insert(-1);
  s.insert(4);

  auto prev_size = s.size();
  try {
    s.insert(-1);
  } catch (const std::exception& e) {

  }
  auto next_size = s.size();
  assert(prev_size == next_size);

  s.dump(std::cout);
#if 0
  for () {
    if (!std::cin || !std::cout) {
      std::abort();
    }

    if (std::cin.fail()) {
      std::abort();
    }
  }

  auto start = std::chrono::high_resolution_clock::now();
  
  auto finish = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration<double, std::milli>(finish - start);
#endif

#if 0
  if (vm.count("count-time")) {
    std::cout << "Time elapsed" << elapsed.count() << " ms\n";
  }
#endif
}
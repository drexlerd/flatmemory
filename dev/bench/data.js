window.BENCHMARK_DATA = {
  "lastUpdate": 1707490615325,
  "repoUrl": "https://github.com/drexlerd/flatmemory",
  "entries": {
    "Benchmark": [
      {
        "commit": {
          "author": {
            "email": "dominik.drexler@gmx.net",
            "name": "Dominik Drexler",
            "username": "drexlerd"
          },
          "committer": {
            "email": "dominik.drexler@gmx.net",
            "name": "Dominik Drexler",
            "username": "drexlerd"
          },
          "distinct": true,
          "id": "f0f6a8038b5c599c32c8e6dc29a33a21c692845e",
          "message": "reset benchmark data",
          "timestamp": "2024-02-09T15:56:03+01:00",
          "tree_id": "fb47653c354c9733b50aa5ec1343b92e5491da6b",
          "url": "https://github.com/drexlerd/flatmemory/commit/f0f6a8038b5c599c32c8e6dc29a33a21c692845e"
        },
        "date": 1707490614793,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/100000/10",
            "value": 3298073.8240740867,
            "unit": "ns/iter",
            "extra": "iterations: 216\ncpu: 3297802.314814815 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/100000/10",
            "value": 444384.2534854273,
            "unit": "ns/iter",
            "extra": "iterations: 1578\ncpu: 444358.87198986067 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/100000/10",
            "value": 663537.5946717426,
            "unit": "ns/iter",
            "extra": "iterations: 1051\ncpu: 663500.8563273074 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/100000/10",
            "value": 375727.9645542398,
            "unit": "ns/iter",
            "extra": "iterations: 1862\ncpu: 375692.5349087002 ns\nthreads: 1"
          }
        ]
      }
    ]
  }
}
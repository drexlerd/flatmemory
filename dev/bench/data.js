window.BENCHMARK_DATA = {
  "lastUpdate": 1707780199400,
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
          "id": "7248d0c75291743092586149ac23f2e4afa7ada0",
          "message": "randomly access bitsets",
          "timestamp": "2024-02-10T00:01:01+01:00",
          "tree_id": "d508de1c89fb8f26215e6b39e8936628cae51de8",
          "url": "https://github.com/drexlerd/flatmemory/commit/7248d0c75291743092586149ac23f2e4afa7ada0"
        },
        "date": 1707519723320,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40400283.30769238,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40399630.769230776 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 64270193.90000055,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 64269730 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45782908.72727435,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 45783363.63636363 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 98704299.49999958,
            "unit": "ns/iter",
            "extra": "iterations: 6\ncpu: 98703600.00000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 392729426.4999972,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 392720450.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 552747051.0000114,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 552718800.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 133669046.20000355,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133668560.00000009 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18261941.34210518,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18261344.736842092 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147557284.1999963,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147557020 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44137609.71428563,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 44136785.714285776 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 342967959.99999577,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 342955599.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 188461498.75000152,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 188462949.9999999 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "8ba162d48ff88650f60411cbf2f176bdefaa5073",
          "message": ".",
          "timestamp": "2024-02-10T00:30:50+01:00",
          "tree_id": "b117c6fb5f74c900750f7a557914bb2e45f4a68b",
          "url": "https://github.com/drexlerd/flatmemory/commit/8ba162d48ff88650f60411cbf2f176bdefaa5073"
        },
        "date": 1707521506874,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41060082.84615388,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 41031430.76923077 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 62049756.199999705,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 62044250 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46745546.09090882,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46744518.181818195 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 98943697.4999999,
            "unit": "ns/iter",
            "extra": "iterations: 6\ncpu: 98932549.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 421053224.4999996,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 421028549.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 510654966.0000042,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 510604199.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136734539.59999904,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136722900 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18841281.783783633,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 18840578.378378358 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 150638670.39999932,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150636420.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45129062.50000067,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45128128.571428604 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 350335847.50000554,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 350331650.00000024 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 195732914.9999983,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 195728833.33333322 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "4b84327d54946c53f7269d83f7e87d58cbab2fe3",
          "message": "switch to byte buffer",
          "timestamp": "2024-02-10T21:23:01+01:00",
          "tree_id": "e60e3bdb232ec79a342f1cc2a314c7535a747d65",
          "url": "https://github.com/drexlerd/flatmemory/commit/4b84327d54946c53f7269d83f7e87d58cbab2fe3"
        },
        "date": 1707596649776,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 36835065.68421087,
            "unit": "ns/iter",
            "extra": "iterations: 19\ncpu: 36830057.89473684 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 42458894.6428567,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 42458957.14285714 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 42804413.91666656,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 42803391.66666665 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 133881341.39999864,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133862740 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 403183544.5000027,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 399644950.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 1088368850.9999986,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 1082401899.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128232595.00000007,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128228340.00000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18499413.82051248,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 18498430.769230783 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 142818769.60000092,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142816500.00000018 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43987020.37499991,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43984350.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 336860907.99999845,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 336849699.9999992 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 185990230.00000158,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 185987833.33333322 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "7248d0c75291743092586149ac23f2e4afa7ada0",
          "message": "randomly access bitsets",
          "timestamp": "2024-02-10T00:01:01+01:00",
          "tree_id": "d508de1c89fb8f26215e6b39e8936628cae51de8",
          "url": "https://github.com/drexlerd/flatmemory/commit/7248d0c75291743092586149ac23f2e4afa7ada0"
        },
        "date": 1707608075532,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41164291.69230811,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 41162723.07692308 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 65886546.7777774,
            "unit": "ns/iter",
            "extra": "iterations: 9\ncpu: 65882655.55555555 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 47929805.545454554,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 47927418.18181818 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 101006769.83333302,
            "unit": "ns/iter",
            "extra": "iterations: 6\ncpu: 101002350.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404058840.4999994,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404044749.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 518295119.0000153,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 518286299.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 145697976.00000244,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145689679.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 24644146.107142717,
            "unit": "ns/iter",
            "extra": "iterations: 28\ncpu: 24643046.428571433 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 154243038.20000204,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 154231500.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 58378907.27272566,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 58377209.09090915 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 350889133.9999991,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 350881249.9999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 201777822.6666659,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 201769466.66666675 ns\nthreads: 1"
          }
        ]
      },
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
          "distinct": false,
          "id": "347f18ad454fde04f5640c0625c5473322f9c998",
          "message": "another iteration",
          "timestamp": "2024-02-11T00:33:04+01:00",
          "tree_id": "1f3275955f66785da38192dc895a85235a95023e",
          "url": "https://github.com/drexlerd/flatmemory/commit/347f18ad454fde04f5640c0625c5473322f9c998"
        },
        "date": 1707608414801,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40019911.85714157,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40017085.71428572 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 58685021.70000056,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 58684819.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45812222.36363787,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 45810200.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95543527.57142834,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95539314.28571431 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 395957421.50000036,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 394916150 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 501680027.0000203,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 501650199.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 129435213.80000219,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 129429820 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18878617.026315603,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18878173.68421052 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 143750058.79999775,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 143744020.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45877564.733333044,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45874899.99999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 332623509.9999906,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 332614099.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 187561767.25000274,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 187558525.00000003 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "338d6c625dff039cc82004fb781f7bac067c124f",
          "message": "changed unit test action to debug mode",
          "timestamp": "2024-02-11T00:40:27+01:00",
          "tree_id": "1157bede19686fc131228c25fe08863fe752f397",
          "url": "https://github.com/drexlerd/flatmemory/commit/338d6c625dff039cc82004fb781f7bac067c124f"
        },
        "date": 1707608491671,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41708909.14285711,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41709171.428571425 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 61353967.40000089,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 61346949.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46585092.266667515,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46585346.66666666 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95202201.00000237,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95192600.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 421460798.99998766,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 418071649.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 500528809.9999916,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 500461600.0000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 142606625.59999558,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142594300.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19981448.057143323,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19978860 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152491815.59999555,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 152480499.99999988 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 52968610.92857139,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 52962514.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 354591870.99999666,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 354585600.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 217368268.3333311,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 217365300.00000027 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "98b176e3acee95c4966a924ccc0a76f11c354b5f",
          "message": "added easier control for memory per segments",
          "timestamp": "2024-02-11T01:05:17+01:00",
          "tree_id": "d6b6321ec595e2d54f9ff7e2cf5ead0f02d241d3",
          "url": "https://github.com/drexlerd/flatmemory/commit/98b176e3acee95c4966a924ccc0a76f11c354b5f"
        },
        "date": 1707610035021,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 42285794.08333152,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 42284616.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 58136178.80000095,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 58130049.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46876400.36363725,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46863790.90909093 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95154814.71428546,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95150600 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 416493180.9999928,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 416467300.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 501883106.00000817,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 501882200.0000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134230757.00000027,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134215180 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20649908.823529854,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 20649252.941176485 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147312909.59999797,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147300300.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47808618.42857169,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 47807135.71428568 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 344165520.9999936,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 344153549.9999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 215076819.99999782,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 215055066.66666698 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "878e99d6cf9a327c8cc5faf3cc6fa30f33f05533",
          "message": "update readme",
          "timestamp": "2024-02-11T01:12:27+01:00",
          "tree_id": "93e4f13b7dcd9477238246dc36e40cff7ed28407",
          "url": "https://github.com/drexlerd/flatmemory/commit/878e99d6cf9a327c8cc5faf3cc6fa30f33f05533"
        },
        "date": 1707610438161,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40186585.07142854,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40183364.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 59805108.2000012,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 59797259.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46138897.999999136,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46137154.54545457 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95220340.71428768,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95219157.1428571 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 397045328.5000133,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 397029099.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 500263666.9999845,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 500246400 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 137825366.0000041,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 137817820.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19214305.388888735,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19213019.444444448 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 150095912.7999977,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150086560.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46096693.28571491,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 46092600.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 349441272.0000071,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 349426900.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 193422526.99999562,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 193407400.00000048 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "7db82eafc91857ee352f3248b79b35cf111a5305",
          "message": "pass segment size at runtime",
          "timestamp": "2024-02-11T12:17:32+01:00",
          "tree_id": "9ce8f3ca2a3de160c8d863fc79171ad00a9fecf0",
          "url": "https://github.com/drexlerd/flatmemory/commit/7db82eafc91857ee352f3248b79b35cf111a5305"
        },
        "date": 1707650315763,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40260377.384614594,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40255784.61538462 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 57918114.00000184,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 57915672.72727272 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46070737.09090834,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46064500.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 94187137.285713,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 94176085.71428572 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 392117620.5000023,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 392099400.00000024 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 506154662.0000001,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 506152000.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132305825.20000097,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132296579.99999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18331918.578947704,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18331081.578947354 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145015537.79999766,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145002279.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44326941.499999605,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44323831.25000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 335698582.99999565,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 335670249.9999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 191013527.50000444,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 191007399.9999997 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "e07353bcc10fe3a3866758ec08e258d7e57a3416",
          "message": "iteration on containers",
          "timestamp": "2024-02-11T13:06:10+01:00",
          "tree_id": "41169c1c36ba339e8ea5a66dfaae5bf813c39ab5",
          "url": "https://github.com/drexlerd/flatmemory/commit/e07353bcc10fe3a3866758ec08e258d7e57a3416"
        },
        "date": 1707653229679,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 38699264.692308605,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 38699107.692307696 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 55961505.54545303,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 55955690.90909092 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 44517800.99999958,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44517568.75 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 91916359.00000148,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 91906885.71428569 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 399487252.0000001,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 399453699.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 484068577.4999969,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 483977149.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 133298915.60000534,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133289760.00000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18129520.205128267,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 18127671.7948718 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145344595.00000027,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145336160.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 42692374.823529385,
            "unit": "ns/iter",
            "extra": "iterations: 17\ncpu: 42691276.47058824 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 337648654.0000059,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 337646350 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 188297353.00000295,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 188293300.0000002 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "3736a2e094dab970108b44b30b5ab155ce80b39c",
          "message": "removed unused byte stream utils",
          "timestamp": "2024-02-11T13:09:00+01:00",
          "tree_id": "faced839cf571a9edb352b23c230f2e2ccdc0136",
          "url": "https://github.com/drexlerd/flatmemory/commit/3736a2e094dab970108b44b30b5ab155ce80b39c"
        },
        "date": 1707653409620,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40259054.46153808,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40258807.692307696 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 58318449.60000012,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 58319419.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46396975.090909176,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46385763.63636362 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95695046.85714087,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95696657.14285712 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 398144633.5000101,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 398093300 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 505193824.99999213,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 505173800.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 139359076.39999527,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 139352560.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21135279.685714588,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 21133382.857142866 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147424576.99999818,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147416919.99999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 56789755.833333306,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 56783566.66666666 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 357798977.49999636,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 357777550.00000066 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 256690892.33333388,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 256675033.33333325 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "c3c753af8460052644fb6a0db88a2d8c839bcba2",
          "message": "rename stream to buffer",
          "timestamp": "2024-02-11T13:23:59+01:00",
          "tree_id": "a9940dad4e60ce08ac368a2dc4f5ff5bcd253850",
          "url": "https://github.com/drexlerd/flatmemory/commit/c3c753af8460052644fb6a0db88a2d8c839bcba2"
        },
        "date": 1707654305815,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41278527.785712935,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41276121.428571425 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 57750508.18181946,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 57749990.90909091 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46505565.99999979,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46493781.818181805 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 94329147.4285713,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 94325685.71428566 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 424399340.5000026,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424344800.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 504242237.99998915,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 501240400.00000036 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128735128.40000102,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128735499.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18583531.184210014,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18583071.052631587 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 143087720.40000123,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 143086199.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43538328.37499993,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43535337.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 333589235.4999999,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 333566600.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 186738048.2499996,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 186735849.99999982 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "51596d9cd658a91d0d3b79f59479daa684197c2e",
          "message": "buffer implementation with direct write",
          "timestamp": "2024-02-11T18:33:14+01:00",
          "tree_id": "96ae868c8dee30631689acc2e11b08688d4b8e33",
          "url": "https://github.com/drexlerd/flatmemory/commit/51596d9cd658a91d0d3b79f59479daa684197c2e"
        },
        "date": 1707672863923,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 37084241.38888944,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 37080211.11111111 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 22106733.49999981,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 22103993.750000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 43264668.416667245,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 43262616.66666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 59480313.40000029,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 59469849.99999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 397941723.0000024,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 394308849.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 457413650.50000125,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 457384349.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131061283.60000184,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131059520.00000016 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20333053.228571072,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20332834.285714287 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 146705838.20000046,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 146703939.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 50116818.92307688,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 50111853.846153885 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 378077997.5000002,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 378037350.0000005 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 200100349.66666505,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 200081966.66666695 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "88916156ff944e73a5d96088772caf158be2829b",
          "message": "work on setting correct buffer size",
          "timestamp": "2024-02-11T19:58:47+01:00",
          "tree_id": "099943eb0583a0ef402a16aad93cc60f28a0f938",
          "url": "https://github.com/drexlerd/flatmemory/commit/88916156ff944e73a5d96088772caf158be2829b"
        },
        "date": 1707677989377,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 36685137.833333984,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 36679200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21605676.218750425,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21605806.249999993 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 43248421.437500186,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43245081.250000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 54691729.54545601,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 54692154.545454554 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 415337100.00000215,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 415317700.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 454979025.0000001,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 452031250.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136365162.200002,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136356300.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18520964.947368298,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18520023.68421052 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152522183.0000021,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 152515640.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45732255.1428559,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45729557.14285713 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 377829231.9999963,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 377799899.9999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 195286562.33333662,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 195280833.33333334 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "f913438b30d0d33cb9961b51b84f923560e45e00",
          "message": ".",
          "timestamp": "2024-02-11T20:00:40+01:00",
          "tree_id": "9a828ed125d325e957adcddd9d49a36371dd2b86",
          "url": "https://github.com/drexlerd/flatmemory/commit/f913438b30d0d33cb9961b51b84f923560e45e00"
        },
        "date": 1707678096566,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 36905263.84210551,
            "unit": "ns/iter",
            "extra": "iterations: 19\ncpu: 36903410.526315786 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21547640.218749996,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21546493.749999993 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 43240393.12500005,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43232856.25000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 53747049.000001185,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 53745227.272727296 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 393312082.00000846,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 393306350 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 446164307.49999833,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 446154500 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 127630838.99999969,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 127626680.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18707336.52631585,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18696802.63157892 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145428831.59999746,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145425420.00000012 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44733452.62499961,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44732768.749999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 363366713.4999996,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 363352500.0000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 188897291.7499956,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 188895300 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "be4eff67ad69b3d74f2ca7a257ddbb4b859380f3",
          "message": ".",
          "timestamp": "2024-02-11T20:28:47+01:00",
          "tree_id": "0111c088a684bebbd336e01775c684b4a11265d0",
          "url": "https://github.com/drexlerd/flatmemory/commit/be4eff67ad69b3d74f2ca7a257ddbb4b859380f3"
        },
        "date": 1707679791706,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 46684969.41666689,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 46685166.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21605427.49999994,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21604253.124999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53626491.10000035,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 53626730 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 54919944.45454586,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 54918009.09090908 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 398961257.50000525,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 398957949.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 461703554.00000316,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 461667550.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 130076163.60000043,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 130074039.99999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19978814.48571418,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19977528.571428567 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 144206213.00000107,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 144203919.99999982 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48630471.35714282,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 48625478.57142856 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 362228494.50000185,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 362228649.9999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 208623858.33333027,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 208614099.99999955 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "4a950005ce8554d9f51ab976a3f8230b5b02d145",
          "message": "removed old byte buffer",
          "timestamp": "2024-02-11T21:33:39+01:00",
          "tree_id": "f4e6e29d1ae4c4bf0c487afc1272913aa6934c0d",
          "url": "https://github.com/drexlerd/flatmemory/commit/4a950005ce8554d9f51ab976a3f8230b5b02d145"
        },
        "date": 1707683683839,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 50279980.09090983,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 50276572.72727274 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21346209.42424297,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 21346063.636363633 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 55735302.000002205,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55734679.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55740209.10000001,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55634169.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 412437229.50000006,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 411120299.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 458282803.00000304,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 454821050.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 151649790.80000192,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151637800.00000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 25482557.035714544,
            "unit": "ns/iter",
            "extra": "iterations: 28\ncpu: 25480039.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 159751773.49999824,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 159735250.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 59057604.454546265,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 59056299.99999995 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 413136139.4999971,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 413094800.00000054 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 242648394.33333424,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 242650666.66666672 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "00a873ad5cf9357eef3c070bf3d99d75a8d71de2",
          "message": "removed explicit writing of padding",
          "timestamp": "2024-02-11T21:35:03+01:00",
          "tree_id": "f6995808101aa1a6977b20dc08dd217164fe7b44",
          "url": "https://github.com/drexlerd/flatmemory/commit/00a873ad5cf9357eef3c070bf3d99d75a8d71de2"
        },
        "date": 1707683763998,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47156768.16666677,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47152900 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20087870.05714266,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20087351.428571433 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53121224.09999915,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 53120210.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55332039.500000015,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55329989.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 416874395.00000066,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 416839600.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 448031372.99999917,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 446722399.99999964 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128004818.7999995,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128002259.99999988 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18224503.815789573,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18221892.105263155 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 142605208.80000058,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142595120.00000018 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44323018.50000009,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44321174.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 339200319.5000015,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 339179549.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 190507702.3333348,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 190493566.66666678 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "4cfb617fbf5a24058ed7e6391f9444b6824abde7",
          "message": "started refactoring computation of positions, end, and alignments",
          "timestamp": "2024-02-11T21:52:35+01:00",
          "tree_id": "3e068d26a6eca946e9876202e8d5da795e6cee9a",
          "url": "https://github.com/drexlerd/flatmemory/commit/4cfb617fbf5a24058ed7e6391f9444b6824abde7"
        },
        "date": 1707684831924,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 48618427.6666665,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 48614791.66666668 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20140887.514285818,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20140048.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 54481091.699999236,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 54480439.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55154145.29999987,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55147260.00000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 424855457.49999434,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424840400.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 451364497.0000001,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 451329950.0000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132621345.6000005,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132619479.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18632695.918919094,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 18631248.648648664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 151950004.99999765,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151943600.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44885883.28571451,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 44882457.14285721 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 362202887.9999988,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 362197650.0000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 192009537.2499979,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 191997200.0000003 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "9e1737dd4febe1e437736860eb835c194cd30f98",
          "message": "added comments",
          "timestamp": "2024-02-11T21:57:40+01:00",
          "tree_id": "6acf9838a479861af86a3907458e37172cce1992",
          "url": "https://github.com/drexlerd/flatmemory/commit/9e1737dd4febe1e437736860eb835c194cd30f98"
        },
        "date": 1707685119660,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47310264.909090064,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 47308972.72727274 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21323717.424242735,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 21323339.393939395 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53811595.899998106,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 53806429.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55396711.000000216,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55390990.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404532507.4999937,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404509800.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 447878453.499996,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 447862699.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 135026260.6000001,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 135023200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19355725.1891895,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 19354518.9189189 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147418399.6000022,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147417079.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47664340.071429074,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 47662392.85714287 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 358776746.00000376,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 358755449.9999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 198514947.74999878,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 198511499.99999994 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "bbe5f9dd76dd062e1d662ee56a9709b2deab63b2",
          "message": "update layout computation",
          "timestamp": "2024-02-11T23:16:59+01:00",
          "tree_id": "823d7b5f476938e2da7a9a5477ff65276ad29a35",
          "url": "https://github.com/drexlerd/flatmemory/commit/bbe5f9dd76dd062e1d662ee56a9709b2deab63b2"
        },
        "date": 1707689882033,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47340359.83333366,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47337491.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20203230.885714367,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20202771.42857143 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53277943.49999948,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 53277360.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55288758.54545458,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 55282663.636363655 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 425152374.50000143,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 425126150.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 450428039.99999845,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 446878200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132185223.79999912,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132182260.00000009 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21074754.411765017,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 21074585.294117656 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 144695354.60000315,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 144690540.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 50283330.46153823,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 50283000.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 362472510.49999815,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 362439399.9999995 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 227517080.33333293,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 227495733.33333352 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "b5d0bb8db8c724f6d6de30516644c9f6ffe2fea9",
          "message": "removed redundant variable",
          "timestamp": "2024-02-11T23:22:22+01:00",
          "tree_id": "5ed8eb3d909901ce7b65cc1b3dfdd8063f42ce01",
          "url": "https://github.com/drexlerd/flatmemory/commit/b5d0bb8db8c724f6d6de30516644c9f6ffe2fea9"
        },
        "date": 1707690211964,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47140060.66666817,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47139616.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20713116.617648266,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 20713252.94117647 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 54155717.200001165,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 54153150 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 57461676.49999734,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 57460559.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 423279261.9999941,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 423251700 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 452305984.9999811,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 452297199.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136559775.3999964,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136560500.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 22387525.25806464,
            "unit": "ns/iter",
            "extra": "iterations: 31\ncpu: 22386919.3548387 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147764243.2000039,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147758999.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 57608322.272725135,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 57602309.09090906 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 387308277.5000114,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 387299849.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 281038752.66666967,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 281009299.9999997 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "b8fe6384dee48a60f83e05321a9c3f0a49278761",
          "message": "added padding to tuple data",
          "timestamp": "2024-02-11T23:26:04+01:00",
          "tree_id": "15387c650c84171e0a69d76460a4af6babe654b7",
          "url": "https://github.com/drexlerd/flatmemory/commit/b8fe6384dee48a60f83e05321a9c3f0a49278761"
        },
        "date": 1707690426570,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47624378.833333485,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47609158.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20318018.62857086,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20316702.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 54500218.49999871,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 54496370.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 56369015.99999931,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 56366790 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 423647016.9999933,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 423639199.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 452113206.5000017,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 452067399.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 140778699.99999848,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 140764400.00000012 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21169869.121212233,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 21164800.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 160612564.25000182,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 160593324.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 51286598.15384559,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 51285338.46153848 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 388375094.50000596,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 388340699.99999964 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 234981955.33333424,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 234974399.99999988 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "728f713dd4763715d1dfde1a5f1282d9e3443938",
          "message": "removed clear function",
          "timestamp": "2024-02-11T23:28:07+01:00",
          "tree_id": "a4d41c30df9c4aed33f8b4949f64577b179fdf17",
          "url": "https://github.com/drexlerd/flatmemory/commit/728f713dd4763715d1dfde1a5f1282d9e3443938"
        },
        "date": 1707690544676,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 49298909.08333334,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 49297816.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20508730.617646955,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 20507829.411764707 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 55053041.80000081,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55048390.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55897452.80000074,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55896430.00000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 425226268.4999977,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 425209850.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 448736627.9999989,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 448687749.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134655510.00000176,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134645060.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19549236.486486398,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 19547794.5945946 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153074313.79999912,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 153065400.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46373588.85714247,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 46370542.85714281 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 363153848.9999997,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 363135349.9999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 196889957.00000095,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 196885699.99999988 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "bbe36f092ddf06fd3fc437e0e79fd250e06a36f6",
          "message": "separated bitset_builder and bitset_view benchmarks",
          "timestamp": "2024-02-11T23:48:25+01:00",
          "tree_id": "ee876325eb176d25d4fc242839d2d6a530733520",
          "url": "https://github.com/drexlerd/flatmemory/commit/bbe36f092ddf06fd3fc437e0e79fd250e06a36f6"
        },
        "date": 1707691775622,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47242482.916667916,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47241058.33333334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53119643.84615591,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 53118815.384615384 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404165947.49999034,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404160499.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128227216.20000264,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128220380.00000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145084287.40000454,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145079639.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 369426680.0000037,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 369403399.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27614924.692307763,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27613338.46153846 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 65759124.90908887,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 65754436.36363637 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 456394406.00000113,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 456383900.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18123257.73684171,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18123276.315789483 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44004251.3333329,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 44002446.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 181621635.24999642,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 181614025 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "8e1a2f1ba4a0f43558c528d919ea28e0b1de645e",
          "message": "added bitset functionality",
          "timestamp": "2024-02-12T00:38:45+01:00",
          "tree_id": "b991350ee451d5efec5c085daeb2dd52e097ebe2",
          "url": "https://github.com/drexlerd/flatmemory/commit/8e1a2f1ba4a0f43558c528d919ea28e0b1de645e"
        },
        "date": 1707694786752,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40751370.85714329,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40750842.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46132263.466666736,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46129253.33333335 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 414520577.4999994,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 414494249.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132355621.79999931,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132348820 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 149373257.79999924,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 149366299.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 372491311.4999993,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 372472500.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28319928.346153762,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 28311007.692307696 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66228916.1000004,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66225729.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 456513185.5000004,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 456502000.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18073277.333333347,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 18072358.974358976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43666014.12499982,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43663531.25 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 182712222.74999842,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 182704900.00000006 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "e69c4b4c73873d5bee6409915681994b0a376c80",
          "message": "made some decltype(auto) more explicit",
          "timestamp": "2024-02-12T00:43:28+01:00",
          "tree_id": "2e766e3cca2c8b231d0018c14ded5c4568466027",
          "url": "https://github.com/drexlerd/flatmemory/commit/e69c4b4c73873d5bee6409915681994b0a376c80"
        },
        "date": 1707695074882,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39263482.92857134,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39261778.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45394783.06666638,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45391726.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 417173982.50000316,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 417128699.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 133383239.39999838,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133014519.99999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148599168.39999983,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148592260.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 377358267.5,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 377355650.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27994591.72000013,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 27989767.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66318646.39999918,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66317490.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 454861682.9999972,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 454836100.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18332622.84615372,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 18331561.53846154 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45021802.9999994,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45019814.28571427 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184164508.50000033,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184158449.99999997 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "655a0406ee847b830bc69d5ba8eab17ac8fb7897",
          "message": "update readme",
          "timestamp": "2024-02-12T00:46:04+01:00",
          "tree_id": "b6ddaeec80b1c3ae69f5ac6b36c45a33ce1d0c61",
          "url": "https://github.com/drexlerd/flatmemory/commit/655a0406ee847b830bc69d5ba8eab17ac8fb7897"
        },
        "date": 1707695226293,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40036795.61538412,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40036830.76923077 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46493213.933333285,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46492506.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 396174236.00000024,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396158400 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136578535.39999962,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136572059.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 155976667.1999995,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 155970740.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 385581784.9999994,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 385558349.9999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27670823.038461156,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27669115.384615388 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67449009.70000032,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67445270 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 458179004.5000034,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 458144050 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18073519.028571434,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 18073505.714285713 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45146702.06666646,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45145800 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 186550312.49999964,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 186544975.00000012 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "d3ed8e9b27e35c926f03ac18fa9915f552415b8c",
          "message": ".",
          "timestamp": "2024-02-12T01:08:55+01:00",
          "tree_id": "e5a0964d65b07d65781d86fecbae3db6daaf6d63",
          "url": "https://github.com/drexlerd/flatmemory/commit/d3ed8e9b27e35c926f03ac18fa9915f552415b8c"
        },
        "date": 1707696610458,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39868408.857143685,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39863814.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46331981.80000022,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46330760.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 414063735.5000081,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 414019949.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136571341.40000266,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136557100 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153006581.50000146,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 152996825 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 389454531.50000733,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 389424700.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27656463.57692311,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27655457.692307692 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 71181904.49999985,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 71180090.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 459551356.0000057,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 459526550.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21812143.972222015,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 21811238.88888888 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 53171314.23076769,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 53169384.615384586 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 228907969.33333492,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 228890233.33333322 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "d29b7cd15e8acbf30caad766e1639090943a2c42",
          "message": ".",
          "timestamp": "2024-02-12T01:10:45+01:00",
          "tree_id": "91a4267b2cc06750b3353fe9e9da34caaf255640",
          "url": "https://github.com/drexlerd/flatmemory/commit/d29b7cd15e8acbf30caad766e1639090943a2c42"
        },
        "date": 1707696704318,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39760209.71428592,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39757335.71428572 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45997518.53333297,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45996853.33333334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 424814219.5,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424084799.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 142406870.0000021,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142396260.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 156225682.99999884,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 156186324.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 401997102.99999934,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 401983099.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27499545.615384594,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27499276.923076928 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67462981.20000063,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67461880 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 456853518.99999917,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 456841649.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21470671.18749968,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21469728.12500002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 52503038.53846105,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 52501646.15384614 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 228291717.6666691,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 228287966.6666669 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "85cf1e9abd4f6fef7a479c85a88df809b8d8b8e4",
          "message": "fix to return const view from tuple",
          "timestamp": "2024-02-12T12:42:00+01:00",
          "tree_id": "9a3bf83e6b04791a832bcb478b9e0958aa42d295",
          "url": "https://github.com/drexlerd/flatmemory/commit/85cf1e9abd4f6fef7a479c85a88df809b8d8b8e4"
        },
        "date": 1707738185060,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39712808.07692123,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 39710469.23076923 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45797386.60000127,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45793973.33333333 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 415523143.50001043,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 415486800.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 129582272.40000042,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 129575140.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148884703.59999815,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148878900.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 368913559.0000063,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 368900800 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27522599.88461521,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27520311.53846154 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66141549.63636503,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66139545.45454545 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 457171599.99999523,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 457106400 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17818270.871795394,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17817541.025641024 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44767051.599999756,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 44766626.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 181740635.74999622,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 181737999.99999994 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "16133ef132a6fac15103eef56276a2491e8df5be",
          "message": "fix unordered_set",
          "timestamp": "2024-02-12T12:58:33+01:00",
          "tree_id": "2a28a8d8125da2a2bb517ff6e9385765ca1ce086",
          "url": "https://github.com/drexlerd/flatmemory/commit/16133ef132a6fac15103eef56276a2491e8df5be"
        },
        "date": 1707739175617,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40230297.07142963,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40230799.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46079583.333333105,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46076373.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 403849981.00000757,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 403839050 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 130341315.20000188,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 130330100.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 156545570.19999516,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 156429379.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 395207787.9999933,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395203050.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27711833.96153823,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27711242.307692304 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67428064.70000175,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67426930.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 467028857.0000025,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 467013649.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18885236.57894693,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18884565.789473675 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46993228.49999987,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 46991742.85714282 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 199482267.66666722,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 199462566.66666666 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "05b9e59514b43004c955cfbd9b7202402349b0ec",
          "message": ".",
          "timestamp": "2024-02-12T13:20:36+01:00",
          "tree_id": "77eb27196f3e4b2d75ff8a04bc01cee1c1275465",
          "url": "https://github.com/drexlerd/flatmemory/commit/05b9e59514b43004c955cfbd9b7202402349b0ec"
        },
        "date": 1707740498109,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41470731.7142862,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41465728.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45858509.666666694,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45857626.66666665 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 407265243.49999946,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 403496600 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131447809.7999995,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131445160 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 149605085.19999963,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 149600820.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 370724885.99999785,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 370695599.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27851680.120000426,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 27850188.000000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66018402.18181885,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66014118.18181817 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 458344844.99999917,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 458324650 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17683517.27499997,
            "unit": "ns/iter",
            "extra": "iterations: 40\ncpu: 17681492.499999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43564634.87500051,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43562806.24999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 180936781.99999985,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 180924150.00000006 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "a1b619feebb8dd1340401b12b943831dd75eb8b9",
          "message": "added back writing of padding bytes 0 to be able to easier compare and hash data based on memcmp and murmurhash",
          "timestamp": "2024-02-12T14:58:19+01:00",
          "tree_id": "1b00a9964fa0c65ef58f4f32e21487fc3b6cb4c6",
          "url": "https://github.com/drexlerd/flatmemory/commit/a1b619feebb8dd1340401b12b943831dd75eb8b9"
        },
        "date": 1707746382312,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40248118.42857088,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40247650.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45847128.666666016,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45843953.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 419330067.4999989,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 419294399.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 133203705.59999903,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133191439.99999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 151494386.59999532,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151485040.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 374493472.0000117,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 374457699.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28249079.95999979,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28249108.000000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66383698.69999963,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66378030 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 459686999.5000077,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 459682500 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17821914.589743614,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17821184.615384605 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43406387.31249946,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43402712.49999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 185112781.49999556,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 185103524.99999994 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "9459449d775ca2133d57e14a2ca2f4ad5a1a248b",
          "message": "work on interface",
          "timestamp": "2024-02-12T15:47:55+01:00",
          "tree_id": "2bc8afaa005350110941d271f313fca7b2712672",
          "url": "https://github.com/drexlerd/flatmemory/commit/9459449d775ca2133d57e14a2ca2f4ad5a1a248b"
        },
        "date": 1707749338987,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41009369.53846074,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 41008176.92307693 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46260830.33333259,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46258940 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 424927809.9999998,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424907350 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136693683.20000216,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136677019.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 154145042.5999983,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 154134339.99999988 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 379207695.0000052,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 379165650 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28430257.875000346,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 28430395.83333333 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67409480.39999922,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67408030.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 478173277.9999999,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 478172300 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19281539.91428628,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19281408.57142857 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47127359.69230791,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 47127761.538461596 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 194823938.33333352,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 194819166.66666672 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "e25bd5143727f33ac68035ed8fe7209e94f4fb83",
          "message": "injected hash functions into std namespace",
          "timestamp": "2024-02-12T15:54:54+01:00",
          "tree_id": "c8cbcaf98c925b1425e6f63eb9a9162af477a416",
          "url": "https://github.com/drexlerd/flatmemory/commit/e25bd5143727f33ac68035ed8fe7209e94f4fb83"
        },
        "date": 1707749763119,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 42380888.35714292,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 42351107.14285714 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46784999.19999979,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46785166.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 418832504.49999565,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 418792599.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 140948586.79999903,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 140938639.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 155648441.19999748,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 155641640.00000018 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 360015765.99999654,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 359994200.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28538197.76000023,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28538296 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67496393.10000077,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67489830 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 461085369.49999744,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 461086700.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20348071.15151521,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 20347696.969696965 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 49277867.307693034,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 49276130.769230805 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 199254076.00000253,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 199234666.66666675 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "9d9d685e4fa014c4d7580e658068eeadaf6cbcba",
          "message": "added operator to reduce code duplication",
          "timestamp": "2024-02-12T22:41:28+01:00",
          "tree_id": "3a052f2ac8f1cfd2d0ff9b1d7cadb7e02fba403a",
          "url": "https://github.com/drexlerd/flatmemory/commit/9d9d685e4fa014c4d7580e658068eeadaf6cbcba"
        },
        "date": 1707774165381,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40093086.928571604,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40092521.428571425 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46407609.99999998,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46405280.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 414638084.00000346,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 414635250.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131483913.39999819,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131480659.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 146254994.59999958,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 146248220.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 341052450.0000065,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 341048500.0000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28279418.999999847,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28278879.999999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66779042.10000066,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66779380.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 461976009.4999989,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 461960799.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18554275.394736778,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18553250.000000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44995187.87500012,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44994331.25000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184991459.24999994,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184987550 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "540532c12c037e74453c327c60ee8edb26c933c8",
          "message": "added working test for bitset iterator",
          "timestamp": "2024-02-13T00:22:09+01:00",
          "tree_id": "81bba60cc3113900e58911e359a9ce1bd4733fee",
          "url": "https://github.com/drexlerd/flatmemory/commit/540532c12c037e74453c327c60ee8edb26c933c8"
        },
        "date": 1707780198812,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39958241.15384913,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 39957730.769230776 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46254183.06666992,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46252806.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 420557035.0000016,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 420542599.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 145610866.6000091,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145606279.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 156065571.25002494,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 156055500.00000012 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 373350132.0000414,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 373332350.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28727507.720000178,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28726008.000000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67253228.69999672,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67250199.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 462606160.0000071,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 462609750.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21784795.677420687,
            "unit": "ns/iter",
            "extra": "iterations: 31\ncpu: 21783751.612903222 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 53388113.6923093,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 53387638.461538464 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 248212206.3333539,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 248209500.00000003 ns\nthreads: 1"
          }
        ]
      }
    ]
  }
}
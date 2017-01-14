## JCH - Jump Consistent Hash Extension for PHP7

A Fast, Minimal Memory, Consistent Hash Algorithm.

> We present jump consistent hash, a fast, minimal memory, consistent hash
> algorithm that can be expressed in about 5 lines of code. In comparison to
> the algorithm of Karger et al., jump consistent hash requires no storage, is
> faster, and does a better job of evenly dividing the key space among the
> buckets and of evenly dividing the workload when the number of buckets
> changes. Its main limitation is that the buckets must be numbered
> sequentially, which makes it more suitable for data storage applications than
> for distributed web caching.

Paper: <https://arxiv.org/abs/1406.2294>

### Usage

```php
$b = jchash("11.22.33.44", 500000);
$b = jchash(4005823, 500000);
```


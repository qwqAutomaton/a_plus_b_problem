let ans = 0;
require('fs').readFileSync('/dev/stdin').toString('utf-8').trim().split(' ').map(v => parseInt(v, 10)).forEach(v => { ans += v; });
console.log(ans);


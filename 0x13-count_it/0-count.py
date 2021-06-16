#!/usr/bin/python3
"""count"""

import requests


def count_words(subreddit, list, after="", count={}):
    """recursive function that queries the Reddit API"""
    if after is None:
        return []
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6)\
     AppleWebKit/605.1.15 (KHTML, like Gecko) Version/14.0.3 Safari/605.1.15'}
    if after:
        url += '?after={}'.format(after)
    req = requests.get(url, headers=headers, allow_redirects=False)
    if str(req) != '<Response [200]>':
        return None
    data = req.json().get('data')
    after = data.get('after')
    list_underlist = data.get('children')
    for under_list in list_underlist:
        title = under_list.get('data').get('title')
        for key in list:
            occ = title.lower().split().count(key.lower())
            if occ > 0:
                if key in count:
                    count[key] += occ
                else:
                    count[key] = occ
    if after is None:
        if not len(count) > 0:
            return
        it = sorted(count.items(), key=lambda kv: (-kv[1], kv[0]))
        for key, value in it:
            print('{}: {}'.format(key.lower(), value))
    else:
        return count_words(subreddit, list, after, count)

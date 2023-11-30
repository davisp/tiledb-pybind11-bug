import pytest

import errortest

class Group(errortest.Group):
    def __init__(self, uri):
        super().__init__(ctx, uri, errortest.QueryType.WRITE)

    def __repr__(self):
        return self._dump(True)

def test_invalid_object_type():
    path = "not_a_group"
    with pytest.raises(ValueError):
        # Should return error that uri is not a Group
        group = Group(uri=path)

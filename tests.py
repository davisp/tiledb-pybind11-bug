import pytest

import errortest

class Group(errortest.Group):
    def __init__(self, uri):
        try:
            ctx = errortest.Context()
            super().__init__(ctx, uri)
        except Exception as exc:
            print(exc)
            raise

    def __repr__(self):
        return self._dump(True)

def test_invalid_object_type():
    path = "not_a_group"
    with pytest.raises(ValueError):
        # Should return error that uri is not a Group
        group = Group(uri=path)


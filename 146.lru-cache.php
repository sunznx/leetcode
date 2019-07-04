class Node
{
    /** @var Node */
    public $prev;

    /** @var Node */
    public $next;

    public $key;

    public $value;

    public function __construct($key = null, $value = null)
    {
        $this->prev = null;
        $this->next = null;
        $this->key = $key;
        $this->value = $value;
    }

    public function isTail()
    {
        return $this->next == null;
    }

    public function isHead()
    {
        return $this->prev == null;
    }
}

class DoubleLinkList
{
    /** @var Node */
    private $head;

    /** @var Node */
    private $tail;

    private $size;

    /** @var Node[] */
    private $map = [];

    public function __construct()
    {
        $this->head = null;
        $this->tail = null;
        $this->size = 0;
    }

    public function size()
    {
        return $this->size;
    }

    public function removeLastElement()
    {
        unset($this->map[$this->tail->key]);
        if ($this->head->isTail()) {
            $this->head = null;
            $this->tail = null;
        } else {
            $this->tail = $this->tail->prev;
            $this->tail->next = null;
        }
        $this->size -= 1;
    }

    private function prependNode(Node $node)
    {
        if ($this->head == null) {
            $this->head = $node;
            $this->tail = $node;
        } else {
            $node->next = $this->head;
            $this->head->prev = $node;
            $this->head = $node;
        }
    }

    public function ifKeyExistInList($key)
    {
        return isset($this->map[$key]);
    }

    public function moveKeyToHead($key)
    {
        if ($this->head->key == $key) {
            return;
        }

        $node = $this->map[$key];
        $node->prev->next = $node->next;
        if ($node->next) {
            $node->next->prev = $node->prev;
        } else {
            $this->tail = $node->prev;
        }
        $node->prev = null;
        $node->next = $this->head;
        $this->head->prev = $node;
        $this->head = $node;
    }

    public function updateValue($key, $value)
    {
        $this->map[$key]->value = $value;
        $this->moveKeyToHead($key);
    }

    public function putValue($key, $value)
    {
        $this->map[$key] = new Node($key, $value);
        $this->size += 1;
        $this->prependNode($this->map[$key]);
    }

    public function getValue($key)
    {
        if ($this->ifKeyExistInList($key)) {
            $this->moveKeyToHead($key);
            return $this->map[$key]->value;
        }
        return -1;
    }
}

class LRUCache
{
    /** @var DoubleLinkList $list */
    private $list;

    private $capacity;

    public function __construct($capacity)
    {
        $this->capacity = $capacity;
        $this->list = new DoubleLinkList();
    }

    public function get($key)
    {
        return $this->list->getValue($key);
    }

    public function put($key, $value)
    {
        if ($this->capacity == 0) {
            return;
        }

        if ($this->list->ifKeyExistInList($key)) {
            $this->list->updateValue($key, $value);
        } else {
            if ($this->isFull()) {
                $this->list->removeLastElement();
            }
            $this->list->putValue($key, $value);
        }
    }

    private function isFull()
    {
        return $this->list->size() == $this->capacity;
    }
}


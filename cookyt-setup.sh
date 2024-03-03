#! /bin/bash

function log() {
  echo >&2 "$@"
}

keyboard=
dryrun=0
for arg in "$@"; do
  case "$arg" in
    -n | --dry_run | --dryrun)
      dryrun=1
      ;;
    -h | --help)
      log "Usage:"
      log "    $0 [-n|--dryrun] KEYBOARD_NAME"
      log "Sets some of my personal QMK config values for" \
               "my various keyboards."
      exit 1
      ;;
    -*)
      log "Unrecognized flag: '$arg'"
      exit 1
      ;;
    *)
      keyboard="$arg"
      ;;
  esac
done

qmk_keyboard=
case "$keyboard" in
  keychron/v1)
    qmk_keyboard=keychron/v1/ansi_encoder
    ;;
  nullbits/snap | nullbitsco/snap | snap)
    qmk_keyboard=nullbitsco/snap/rp2040
    ;;
  "")
    log "First arg must be the name of the keyboard you want"
    log "Allowed: keychron/v1 snap"
    exit 1
    ;;
  *)
    log "Unsupported keyboard: $keyboard"
    log "Allowed: keychron/v1 snap"
    exit 1
    ;;
esac

function logcall() {
  local dryrun_msg=
  if (( "$dryrun" )); then
    dryrun_msg="DRYRUN: "
  fi

  log "${dryrun_msg}EXECUTING COMMAND:"
  log "$dryrun_msg  $1"
  for arg in "${@:2}"; do
    log "$dryrun_msg    $arg"
  done
  log

  if !(( "$dryrun" )); then
    "$@"
  fi
}

script_dir="$(dirname -- "$(readlink -f -- "$0")")"

cd "$script_dir"
logcall qmk config user.qmk_home="$script_dir"
logcall qmk config user.keyboard="$qmk_keyboard"
logcall qmk config user.keymap="cookyt"
logcall qmk generate-compilation-database
